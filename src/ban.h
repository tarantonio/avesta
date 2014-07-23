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

#ifndef __OTSERV_BAN_H__
#define __OTSERV_BAN_H__

#include "definitions.h"

#include <list>
#include <vector>
#include <boost/thread.hpp>

struct LoginBlock{
	uint32_t lastLoginTime;
	uint32_t numberOfLogins;
};

struct ConnectBlock{
	uint64_t lastConnection;
};

typedef std::map<uint32_t, LoginBlock > IpLoginMap;
typedef std::map<uint32_t, ConnectBlock > IpConnectMap;

enum BanType_t{
	BANTYPE_IP_BANISHMENT = 1,
	BANTYPE_NAMELOCK = 2,
	BANTYPE_BANISHMENT = 3,
	BANTYPE_NOTATION = 4,
	BANTYPE_DELETION = 5
};

struct Ban {
	BanType_t type;
	uint32_t id, added, expires, adminid;
	std::string reason, comment, value, param;
};

class BanManager {
public:
	BanManager();
	~BanManager();

	void loadSettings();
	bool clearTemporaryBans();

	bool isIpBanished(uint32_t ip, uint32_t mask = 0xFFFFFFFF) const;
	bool isNameLocked(std::string name) const;
	bool isBanished(uint32_t account) const;
	bool isDeleted(uint32_t account) const;
	bool isIpDisabled(uint32_t clientip) const;

	void addIpBanishment(uint32_t ip, uint32_t time, uint32_t adminId, std::string reason, std::string comment);
	void addNamelock(std::string name, uint32_t adminId, std::string reason, std::string comment);
	void addBanishment(std::string name, uint32_t time, uint32_t adminId, std::string reason, std::string comment);
	void addDeletion(std::string name, uint32_t adminId, std::string reason, std::string comment);
	void addNotation(std::string name, uint32_t adminId, std::string reason, std::string comment);

	bool removeIpBanishment(uint32_t ip);
	bool removeNamelock(std::string name);
	bool removeBanishment(std::string name);
	bool removeDeletion(std::string name);
	bool removeNotations(std::string name);

	bool acceptConnection(uint32_t clientip);
	void addConnectionAttempt(uint32_t clientup);
	void addLoginAttempt(uint32_t clientip, bool isSuccess);

	uint32_t getNotationsCount(uint32_t account);

	std::vector<Ban> getBans(BanType_t type) const;
protected:
	IpLoginMap ipLoginMap;
	IpConnectMap ipConnectMap;

	uint32_t loginTimeout;
	uint32_t maxLoginTries;
	uint32_t retryTimeout;

	mutable boost::recursive_mutex banLock;

	friend class IOBan;
};

#endif
