//////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#include "otpch.h"

#include "ban.h"
#include "ioplayer.h"
#include "configmanager.h"
#include "tools.h"
#include "database.h"

#include <sstream>

extern ConfigManager g_config;

BanManager::BanManager()
{
}

BanManager::~BanManager()
{
}

void BanManager::loadSettings()
{
	maxLoginTries = (uint32_t)g_config.getNumber(ConfigManager::LOGIN_TRIES);
	retryTimeout = (uint32_t)g_config.getNumber(ConfigManager::RETRY_TIMEOUT) / 1000;
	loginTimeout = (uint32_t)g_config.getNumber(ConfigManager::LOGIN_TIMEOUT) / 1000;
}

bool BanManager::clearTemporaryBans() 
{
	Database* db = Database::instance();
	DBQuery query;
	query << "UPDATE `bans` SET `active` = 0 WHERE `expires` = 0";
	return db->executeQuery(query.str());
}

bool BanManager::isIpBanished(uint32_t clientip, uint32_t mask /*= 0xFFFFFFFF*/) const
{
	if(clientip != 0){
		Database* db = Database::instance();
		DBQuery query;
		DBResult* result;

		uint32_t currentTime = std::time(NULL);
		query <<
			"SELECT "
				"COUNT(*) AS `count` "
			"FROM "
				"`bans` "
			"WHERE "
				"`type` = " << BANTYPE_IP_BANISHMENT << " AND "
				"((" << clientip << " & " << mask << " & `param`) = (`value` & `param` & " << mask << ")) AND "
				"`active` = 1 AND "
				"(`expires` >= " << currentTime << " OR `expires` = 0)";

		if((result = db->storeQuery(query.str())) != NULL){
			int t = result->getDataInt("count");
			db->freeResult(result);
			return t > 0;
		}
		db->freeResult(result);
	}

	return false;
}

bool BanManager::isNameLocked(std::string name) const
{
	Database* db = Database::instance();
	DBResult* result;
	DBQuery query;

	uint32_t _guid;
	if (!IOPlayer::instance()->getGuidByName(_guid, name)) {
		return false;
	}

	query << "SELECT `id` FROM `bans` WHERE `value` = " << _guid << " AND `type` = " << BANTYPE_NAMELOCK << " AND `active` = 1";
	if(!(result = db->storeQuery(query.str())))
		return false;

	db->freeResult(result);
	return true;
}

bool BanManager::isBanished(uint32_t account) const
{
	Database* db = Database::instance();
	DBResult* result;
	DBQuery query;

	query << "SELECT `expires` FROM `bans` WHERE `value` = " << account << " AND `type` = " << BANTYPE_BANISHMENT << " AND `active` = 1";
	if(!(result = db->storeQuery(query.str())))
		return false;

	uint64_t expires = result->getDataInt("expires");
	db->freeResult(result);
	if(expires == 0 || (uint64_t)time(NULL) <= expires)
		return true;

	return false;
}

bool BanManager::isDeleted(uint32_t account) const
{
	Database* db = Database::instance();
	DBResult* result;
	DBQuery query;

	query << "SELECT `id` FROM `bans` WHERE `value` = " << account << " AND `type` = " << BANTYPE_DELETION << " AND `active` = 1";
	if(!(result = db->storeQuery(query.str())))
		return false;

	db->freeResult(result);
	return true;
}

bool BanManager::isIpDisabled(uint32_t clientip) const
{
	if(maxLoginTries == 0)
		return false;

	if(clientip != 0){
		banLock.lock();

		uint32_t currentTime = std::time(NULL);
		IpLoginMap::const_iterator it = ipLoginMap.find(clientip);
		if(it != ipLoginMap.end()){
			if( (it->second.numberOfLogins >= maxLoginTries) &&
				(currentTime < it->second.lastLoginTime + loginTimeout) )
			{
				banLock.unlock();
				return true;
			}
		}

		banLock.unlock();
	}

	return false;
}

bool BanManager::acceptConnection(uint32_t clientip)
{
	if(clientip == 0)
		return false;

	banLock.lock();

	uint64_t currentTime = OTSYS_TIME();

	IpConnectMap::iterator it = ipConnectMap.find(clientip);
	if(it == ipConnectMap.end()){
		ConnectBlock cb;
		cb.lastConnection = currentTime;

		ipConnectMap[clientip] = cb;

		banLock.unlock();
		return true;
	}

	if(currentTime - it->second.lastConnection < 1000){
		banLock.unlock();
		return false;
	}

	it->second.lastConnection = currentTime;

	banLock.unlock();
	return true;
}

void BanManager::addLoginAttempt(uint32_t clientip, bool isSuccess)
{
	if(clientip != 0){
		banLock.lock();

		uint32_t currentTime = std::time(NULL);

		IpLoginMap::iterator it = ipLoginMap.find(clientip);
		if(it == ipLoginMap.end()){
			LoginBlock lb;
			lb.lastLoginTime = 0;
			lb.numberOfLogins = 0;

			ipLoginMap[clientip] = lb;
			it = ipLoginMap.find(clientip);
		}

		if(it->second.numberOfLogins >= maxLoginTries){
			it->second.numberOfLogins = 0;
		}

		if(!isSuccess || (currentTime < it->second.lastLoginTime + retryTimeout)){
			++it->second.numberOfLogins;
		}
		else{
			it->second.numberOfLogins = 0;
		}

		it->second.lastLoginTime = currentTime;

		banLock.unlock();
	}
}

void BanManager::addIpBanishment(uint32_t ip, uint32_t time, uint32_t adminId, std::string reason, std::string comment)
{
	if(ip == 0 || isIpBanished(ip)) 
		return;

	Database* db = Database::instance();
	DBInsert stmt(db);
	DBQuery query;

	stmt.setQuery("INSERT INTO `bans` (`type`, `value`, `param`, `expires`, `added`, `admin_id`, `reason`, `comment`) VALUES ");

	query << BANTYPE_IP_BANISHMENT << ", " << ip << ", 4294967295, " << time << ", " << std::time(NULL) << ", " << adminId << ", \"" << reason << "\", " << db->escapeString(comment);
	if(!stmt.addRow(query.str())){
		return;
	}

	if(!stmt.execute()){
		return;
	}
}

void BanManager::addNamelock(std::string name, uint32_t adminId, std::string reason, std::string comment)
{
	uint32_t _guid;
	if (!IOPlayer::instance()->getGuidByName(_guid, name) || isNameLocked(name))
		return;

	Database* db = Database::instance();
	DBInsert stmt(db);
	DBQuery query;

	stmt.setQuery("INSERT INTO `bans` (`type`, `value`, `expires`, `added`, `admin_id`, `reason`, `comment`) VALUES");
		
	query << BANTYPE_NAMELOCK << ", " << _guid << ", '-1', " << std::time(NULL) << ", " << adminId << ", \"" << reason << "\", " << db->escapeString(comment);
	if(!stmt.addRow(query.str())){
		return;
	}

	if(!stmt.execute()){
		return;
	}
}

void BanManager::addBanishment(std::string name, uint32_t time, uint32_t adminId, std::string reason, std::string comment)
{
	uint32_t account = IOPlayer::instance()->getAccountIdByName(name);
	if (!account || isBanished(account) || isDeleted(account))
		return;

	Database* db = Database::instance();
	DBInsert stmt(db);
	DBQuery query;

	stmt.setQuery("INSERT INTO `bans` (`type`, `value`, `expires`, `added`, `admin_id`, `reason`, `comment`) VALUES ");

	query << BANTYPE_BANISHMENT << ", " << account << ", " << time << ", " << std::time(NULL) << ", " << adminId << ", \"" << reason << "\", " << db->escapeString(comment);
	if(!stmt.addRow(query.str())){
		return;
	}

	if(!stmt.execute()){
		return;
	}
}

void BanManager::addDeletion(std::string name, uint32_t adminId, std::string reason, std::string comment)
{
	uint32_t account = IOPlayer::instance()->getAccountIdByName(name);
	if (!account || isDeleted(account))
		return;

	Database* db = Database::instance();
	DBInsert stmt(db);
	DBQuery query;

	stmt.setQuery("INSERT INTO `bans` (`type`, `value`, `expires`, `added`, `admin_id`, `reason`, `comment`) VALUES");
	query << BANTYPE_DELETION << ", " << account << ", '-1', " << time(NULL) << ", " << adminId << ", \"" << reason << "\", " << db->escapeString(comment);
	if(!stmt.addRow(query.str())){
		return;
	}

	if(!stmt.execute()){
		return;
	}
}

void BanManager::addNotation(std::string name, uint32_t adminId, std::string reason, std::string comment)
{
	uint32_t account = IOPlayer::instance()->getAccountIdByName(name);
	if (!account)
		return;

	Database* db = Database::instance();
	DBInsert stmt(db);
	DBQuery query;

	stmt.setQuery("INSERT INTO `bans` (`type`, `value`, `expires`, `added`, `admin_id`, `reason`, `comment`) VALUES");
	query << BANTYPE_NOTATION << ", " << account << ", '-1', " << time(NULL) << ", " << adminId << ", \"" << reason << "\", " << db->escapeString(comment);
	if(!stmt.addRow(query.str())){
		return;
	}

	if(!stmt.execute()){
		return;
	}
}

bool BanManager::removeIpBanishment(uint32_t ip)
{
	Database* db = Database::instance();
	DBQuery query;
	query << "UPDATE `bans` SET `active` = 0 WHERE `type` = " << BANTYPE_IP_BANISHMENT << " AND `value` = " << ip  << " AND `active` = 1";
	return db->executeQuery(query.str());
}

bool BanManager::removeNamelock(std::string name)
{
	uint32_t _guid;
	if (!IOPlayer::instance()->getGuidByName(_guid, name))
		return false;

	Database* db = Database::instance();
	DBQuery query;
	query << "UPDATE `bans` SET `active` = 0 WHERE `value` = " << _guid << " AND `type` = " << BANTYPE_NAMELOCK << " AND `active` = 1";
	return db->executeQuery(query.str());
}

bool BanManager::removeBanishment(std::string name)
{
	uint32_t account = IOPlayer::instance()->getAccountIdByName( name);
	if (!account)
		return false;

	Database* db = Database::instance();
	DBQuery query;
	query << "UPDATE `bans` SET `active` = 0 WHERE `value` = " << account << " AND `type` = " << BANTYPE_BANISHMENT << " AND `active` = 1";
	return db->executeQuery(query.str());
}

bool BanManager::removeDeletion(std::string name)
{
	uint32_t account = IOPlayer::instance()->getAccountIdByName(name);
	if (!account)
		return false;

	Database* db = Database::instance();
	DBQuery query;
	query << "UPDATE `bans` SET `active` = 0 WHERE `value` = " << account << " AND `type` = " << BANTYPE_DELETION << " AND `active` = 1";
	return db->executeQuery(query.str());
}

bool BanManager::removeNotations(std::string name)
{
	uint32_t account = IOPlayer::instance()->getAccountIdByName(name);
	if (!account)
		return false;

	Database* db = Database::instance();
	DBQuery query;
	query << "UPDATE `bans` SET `active` = 0 WHERE `value` = " << account << " AND `type` = " << BANTYPE_NOTATION << " AND `active` = 1";
	return db->executeQuery(query.str());
}

uint32_t BanManager::getNotationsCount(uint32_t account)
{
	Database* db = Database::instance();
	DBResult* result;
	DBQuery query;

	query << "SELECT COUNT(`id`) AS `count` FROM `bans` WHERE `value` = " << account << " AND `type` = " << BANTYPE_NOTATION << " AND `active` = 1";
	if(!(result = db->storeQuery(query.str())))
		return 0;

	const uint32_t count = result->getDataInt("count");
	db->freeResult(result);
	return count;
}

std::vector<Ban> BanManager::getBans(BanType_t type) const 
{
	assert(type == BANTYPE_IP_BANISHMENT || type == BANTYPE_NAMELOCK || type == BANTYPE_BANISHMENT);

	Database* db = Database::instance();
	DBQuery query;
	DBResult* result;

	uint32_t currentTime = std::time(NULL);
	query <<
		"SELECT "
			"`id`, "
			"`value`, "
			"`param`, "
			"`expires`, "
			"`added`, "
			"`admin_id`, "
			"`reason`, "
			"`comment` "
		"FROM "
			"`bans` "
		"WHERE "
			"`type` = " << type << " AND "
			"`active` = 1 AND " <<
			"(`expires` >= " << currentTime << " OR `expires` = 0)";

	std::vector<Ban> vec;
	if((result = db->storeQuery(query.str())) != NULL){
		do {
			Ban ban;
			ban.type = type;
			ban.id = result->getDataInt("id");
			ban.value = result->getDataString("value");
			ban.param = result->getDataString("param");
			ban.expires = (uint32_t)result->getDataLong("expires");
			ban.added = (uint32_t)result->getDataLong("id");
			ban.adminid = result->getDataInt("admin_id");
			ban.reason = result->getDataString("reason");
			ban.comment = result->getDataString("comment");
			vec.push_back(ban);
		} while(result->next());

		db->freeResult(result);
	}
	return vec;
}
