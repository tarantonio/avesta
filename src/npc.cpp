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

#include "npc.h"
#include "game.h"
#include "tools.h"
#include "configmanager.h"
#include "position.h"
#include "spells.h"
#include "player.h"
#include "luascript.h"

#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <fstream>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

extern ConfigManager g_config;
extern Game g_game;
extern Spells* g_spells;

AutoList<Npc> Npc::listNpc;

NpcScriptInterface* Npc::m_scriptInterface = NULL;

#ifdef __ENABLE_SERVER_DIAGNOSTIC__
uint32_t Npc::npcCount = 0;
#endif

void Npcs::reload()
{
	delete Npc::m_scriptInterface;
	Npc::m_scriptInterface = NULL;

	for(AutoList<Npc>::listiterator it = Npc::listNpc.list.begin(); it != Npc::listNpc.list.end(); ++it){
		it->second->reload();
	}
}

Npc* Npc::createNpc(const std::string& name)
{
	Npc* npc = new Npc(name);
	if(!npc){
		return NULL;
	}

	if(!npc->load()){
		delete npc;
		return NULL;
	}

	return npc;
}

Npc::Npc(const std::string& _name) :
	Creature()
{
	m_datadir = g_config.getString(ConfigManager::DATA_DIRECTORY);
	m_scriptdir = m_datadir + "npc/scripts/";
	m_filename = m_datadir + "npc/" + _name + ".xml";
	loaded = false;

	m_npcEventHandler = NULL;
	reset();

#ifdef __ENABLE_SERVER_DIAGNOSTIC__
	npcCount++;
#endif
}

Npc::~Npc()
{
	reset();

#ifdef __ENABLE_SERVER_DIAGNOSTIC__
	npcCount--;
#endif
}

bool Npc::load()
{
	if(isLoaded()){
		return true;
	}

	reset();

	if(!m_scriptInterface){
		m_scriptInterface = new NpcScriptInterface();
		m_scriptInterface->loadNpcLib(std::string(m_datadir + "npc/scripts/lib/npc.lua"));
	}

	loaded = loadFromXml(m_filename);
	return isLoaded();
}

void Npc::reset()
{
	loaded = false;
	walkTicks = 1500;
	floorChange = false;
	attackable = false;
	hasScriptedFocus = false;
	focusCreature = 0;
	idleTime = 0;
	idleInterval = 30000;
	walkDelay = 0;

	delete m_npcEventHandler;
	m_npcEventHandler = NULL;

	queueList.clear();
	m_parameters.clear();
}

void Npc::reload()
{
	reset();
	load();

	//Simulate that the creature is placed on the map again.
	if(m_npcEventHandler){
		m_npcEventHandler->onCreatureAppear(this);
	}

	if(walkTicks > 0){
		addEventWalk();
	}
}

bool Npc::loadFromXml(const std::string& filename)
{
	xmlDocPtr doc = xmlParseFile(filename.c_str());

	if(doc){
		xmlNodePtr root, p;
		root = xmlDocGetRootElement(doc);

		if(xmlStrcmp(root->name,(const xmlChar*)"npc") != 0){
			std::cerr << "Malformed XML" << std::endl;
			return false;
		}

		int intValue;
		std::string strValue;

		p = root->children;
		
		std::string scriptfile = "";
		if(readXMLString(root, "script", strValue)){
			scriptfile = strValue;
		}

		if(readXMLString(root, "name", strValue)){
			name = strValue;
		}
		else
			name = "";

		if(readXMLInteger(root, "speed", intValue)){
			baseSpeed = intValue;
		}
		else
			baseSpeed = 110;

		if(readXMLInteger(root, "attackable", intValue)){
			attackable = (intValue != 0);
		}

		if(readXMLInteger(root, "walkinterval", intValue)){
			walkTicks = intValue;
		}

		if(readXMLInteger(root, "floorchange", intValue)){
			floorChange = (intValue != 0);
		}

		if(readXMLInteger(root, "idleinterval", intValue)){
			idleInterval = intValue;
		}

		while(p){
			if(xmlStrcmp(p->name, (const xmlChar*)"health") == 0){

				if(readXMLInteger(p, "now", intValue)){
					health = intValue;
				}
				else
					health = 100;

				if(readXMLInteger(p, "max", intValue)){
					healthMax = intValue;
				}
				else
					healthMax = 100;
			}
			else if(xmlStrcmp(p->name, (const xmlChar*)"look") == 0){

				if(readXMLInteger(p, "type", intValue)){
					defaultOutfit.lookType = intValue;

					if(readXMLInteger(p, "head", intValue)){
						defaultOutfit.lookHead = intValue;
					}

					if(readXMLInteger(p, "body", intValue)){
						defaultOutfit.lookBody = intValue;
					}

					if(readXMLInteger(p, "legs", intValue)){
						defaultOutfit.lookLegs = intValue;
					}

					if(readXMLInteger(p, "feet", intValue)){
						defaultOutfit.lookFeet = intValue;
					}
				}
				else if(readXMLInteger(p, "typeex", intValue)){
					defaultOutfit.lookTypeEx = intValue;
				}

				currentOutfit = defaultOutfit;
			}

			p = p->next;
		}

		xmlFreeDoc(doc);

		if(!scriptfile.empty()){
			m_npcEventHandler = new NpcScript(m_scriptdir + scriptfile, this);
			if(!m_npcEventHandler->isLoaded()){
				return false;
			}
		}

		return true;
	}

	return false;
}

uint32_t Npc::loadParams(xmlNodePtr node)
{
    return 0;
}

bool Npc::canSee(const Position& pos) const
{
	if(pos.z != getPosition().z){
		return false;
	}

	return Creature::canSee(getPosition(), pos, Map::maxClientViewportX, Map::maxClientViewportY);
}

std::string Npc::getDescription(int32_t lookDistance) const
{
	std::stringstream s;
	s << name << ".";
	return s.str();
}

void Npc::onAddTileItem(const Tile* tile, const Position& pos, const Item* item)
{
	Creature::onAddTileItem(tile, pos, item);
}

void Npc::onUpdateTileItem(const Tile* tile, const Position& pos, uint32_t stackpos,
	const Item* oldItem, const ItemType& oldType, const Item* newItem, const ItemType& newType)
{
	Creature::onUpdateTileItem(tile, pos, stackpos, oldItem, oldType, newItem, newType);
}

void Npc::onRemoveTileItem(const Tile* tile, const Position& pos, uint32_t stackpos,
	const ItemType& iType, const Item* item)
{
	Creature::onRemoveTileItem(tile, pos, stackpos, iType, item);
}

void Npc::onUpdateTile(const Tile* tile, const Position& pos)
{
	Creature::onUpdateTile(tile, pos);
}

void Npc::onCreatureAppear(const Creature* creature, bool isLogin)
{
	Creature::onCreatureAppear(creature, isLogin);

	if(creature == this && walkTicks > 0){
		addEventWalk();
	}

	if(creature == this){
		if(m_npcEventHandler){
			m_npcEventHandler->onCreatureAppear(creature);
		}
	}
	//only players for script events
	else if(Player* player = const_cast<Player*>(creature->getPlayer())){
		if(m_npcEventHandler){
			m_npcEventHandler->onCreatureAppear(creature);
		}
	}
}

void Npc::onCreatureDisappear(const Creature* creature, uint32_t stackpos, bool isLogout)
{
	Creature::onCreatureDisappear(creature, stackpos, isLogout);

	if(creature == this){

		/*
		Can't use this yet because Jiddo's scriptsystem isn't able to handle it.
		if(m_npcEventHandler){
			m_npcEventHandler->onCreatureDisappear(creature);
		}
		*/
	}
	//only players for script events
	else if(Player* player = const_cast<Player*>(creature->getPlayer())){
		if(m_npcEventHandler){
			m_npcEventHandler->onCreatureDisappear(creature);
		}
	}
}

void Npc::onCreatureMove(const Creature* creature, const Tile* newTile, const Position& newPos,
		const Tile* oldTile, const Position& oldPos, uint32_t oldStackPos, bool teleport)
{
	Creature::onCreatureMove(creature, newTile, newPos, oldTile, oldPos, oldStackPos, teleport);

	if(creature == this){
		if(m_npcEventHandler){
			m_npcEventHandler->onCreatureMove(creature, oldPos, newPos);
		}
	}
	else if(Player* player = const_cast<Player*>(creature->getPlayer())){
		if(m_npcEventHandler){
			m_npcEventHandler->onCreatureMove(creature, oldPos, newPos);
		}
	}
}

void Npc::onCreatureTurn(const Creature* creature, uint32_t stackpos)
{
	Creature::onCreatureTurn(creature, stackpos);
}

void Npc::onCreatureSay(const Creature* creature, SpeakClasses type, const std::string& text)
{
	if(creature->getID() == this->getID())
		return;

	//only players for script events
	if(const Player* player = creature->getPlayer()){
		if(m_npcEventHandler){
			m_npcEventHandler->onCreatureSay(player, type, text);
		}
	}
}

void Npc::onCreatureChangeOutfit(const Creature* creature, const Outfit_t& outfit)
{
	#ifdef __DEBUG_NPC__
		std::cout << "Npc::onCreatureChangeOutfit" << std::endl;
	#endif
}

void Npc::onPlayerEnter(Player* player)
{
}

void Npc::onPlayerLeave(Player* player)
{
}

void Npc::onThink(uint32_t interval)
{
	Creature::onThink(interval);
	if(m_npcEventHandler){
		m_npcEventHandler->onThink();
	}
}

void Npc::doSay(std::string msg, uint32_t delay)
{
	Scheduler::getScheduler().addEvent(createSchedulerTask(
				delay, boost::bind(&Game::internalCreatureSay, &g_game, this, SPEAK_SAY, msg)));
}

void Npc::doMove(Direction dir)
{
	g_game.internalMoveCreature(this, dir);
}

void Npc::doTurn(Direction dir)
{
	g_game.internalCreatureTurn(this, dir);
}

bool Npc::getNextStep(Direction& dir)
{
	if(Creature::getNextStep(dir)){
		return true;
	}

	if(walkTicks <= 0){
		return false;
	}

	if (hasWalkDelay()) {
		return false;
	}

	if(!isIdle() || focusCreature != 0){
		return false;
	}

	if(getTimeSinceLastMove() < walkTicks){
		return false;
	}

	return getRandomStep(dir);
}

bool Npc::canWalkTo(const Position& fromPos, Direction dir)
{
	Position toPos = fromPos;

	switch(dir){
		case NORTH:
			toPos.y -= 1;
			break;

		case SOUTH:
			toPos.y += 1;
			break;

		case WEST:
			toPos.x -= 1;
			break;

		case EAST:
			toPos.x += 1;
			break;

		default:
			break;
	}

	bool result = Spawns::getInstance()->isInZone(masterPos, masterRadius, toPos);
	if(!result){
		return false;
	}

	Tile* tile = g_game.getTile(toPos.x, toPos.y, toPos.z);
	if(!tile || tile->__queryAdd(0, this, 1, 0) != RET_NOERROR){
		return false;
	}

	if(!floorChange && (tile->floorChange() || tile->getTeleportItem() || tile->hasHeight(1))){
		return false;
	}

	return true;
}

bool Npc::getRandomStep(Direction& dir)
{
	std::vector<Direction> dirList;
	const Position& creaturePos = getPosition();

	if(canWalkTo(creaturePos, NORTH)){
		dirList.push_back(NORTH);
	}

	if(canWalkTo(creaturePos, SOUTH)){
		dirList.push_back(SOUTH);
	}

	if(canWalkTo(creaturePos, EAST)){
		dirList.push_back(EAST);
	}

	if(canWalkTo(creaturePos, WEST)){
		dirList.push_back(WEST);
	}

	if(!dirList.empty()){
		std::random_shuffle(dirList.begin(), dirList.end());
		dir = dirList[random_range(0, dirList.size() - 1)];
		return true;
	}

	return false;
}

void Npc::doMoveTo(Position target)
{
	std::list<Direction> listDir;
	if(!g_game.getPathToEx(this, target, listDir, 1, 1, true, true)){
		return;
	}

	startAutoWalk(listDir);
}

void Npc::setCreatureFocus(Creature* creature)
{
	if(creature){
		focusCreature = creature->getID();
		g_game.internalCreatureTurn(this, getDir(creature));
	}
	else{
		focusCreature = 0;
	}
}

Direction Npc::getDir(Creature* creature)
{
	Direction dir = SOUTH;

	if (creature) {
		const Position& creaturePos = creature->getPosition();
		const Position& myPos = getPosition();
		int32_t dx = myPos.x - creaturePos.x;
		int32_t dy = myPos.y - creaturePos.y;

		float tan = 0;

		if(dx != 0){
			tan = dy / dx;
		}
		else{
			tan = 10;
		}

		if(std::abs(tan) < 1){
			if(dx > 0){
				dir = WEST;
			}
			else{
				dir = EAST;
			}
		}
		else{
			if(dy > 0){
				dir = NORTH;
			}
			else{
				dir = SOUTH;
			}
		}
	}

	return dir;
}

NpcScriptInterface* Npc::getScriptInterface()
{
	return m_scriptInterface;
}

NpcScriptInterface::NpcScriptInterface() :
LuaScriptInterface("Npc interface")
{
	m_libLoaded = false;
	initState();
}


NpcScriptInterface::~NpcScriptInterface()
{
	//
}

bool NpcScriptInterface::initState()
{
	return LuaScriptInterface::initState();
}

bool NpcScriptInterface::closeState()
{
	m_libLoaded = false;
	return LuaScriptInterface::closeState();
}

bool NpcScriptInterface::loadNpcLib(std::string file)
{
	if(m_libLoaded)
		return true;

	if(loadFile(file) == -1){
		std::cout << "Warning: [NpcScriptInterface::loadNpcLib] Can not load " << file  << std::endl;
		return false;
	}

	m_libLoaded = true;
	return true;
}

void NpcScriptInterface::registerFunctions()
{
	LuaScriptInterface::registerFunctions();

	//npc exclusive functions
	lua_register(m_luaState, "selfSay", NpcScriptInterface::luaActionSay);
	lua_register(m_luaState, "selfMove", NpcScriptInterface::luaActionMove);
	lua_register(m_luaState, "selfMoveTo", NpcScriptInterface::luaActionMoveTo);
	lua_register(m_luaState, "selfTurn", NpcScriptInterface::luaActionTurn);
	lua_register(m_luaState, "selfFollow", NpcScriptInterface::luaActionFollow);
	lua_register(m_luaState, "selfGetPosition", NpcScriptInterface::luaSelfGetPos);
	lua_register(m_luaState, "creatureGetName", NpcScriptInterface::luaCreatureGetName);
	lua_register(m_luaState, "creatureGetName2", NpcScriptInterface::luaCreatureGetName2);
	lua_register(m_luaState, "creatureGetPosition", NpcScriptInterface::luaCreatureGetPos);
	lua_register(m_luaState, "getDistanceTo", NpcScriptInterface::luaGetDistanceTo);
	lua_register(m_luaState, "doNpcSetCreatureFocus", NpcScriptInterface::luaSetNpcFocus);
	lua_register(m_luaState, "getNpcCid", NpcScriptInterface::luaGetNpcCid);
	lua_register(m_luaState, "getNpcPos", NpcScriptInterface::luaGetNpcPos);
	lua_register(m_luaState, "getNpcName", NpcScriptInterface::luaGetNpcName);

	lua_register(m_luaState, "getNpcFocus", NpcScriptInterface::luaGetNpcFocus);
	lua_register(m_luaState, "setNpcFocus", NpcScriptInterface::luaSetNpcFocus);
	lua_register(m_luaState, "isNpcIdle", NpcScriptInterface::luaIsNpcIdle);
	lua_register(m_luaState, "resetNpcIdle", NpcScriptInterface::luaResetNpcIdle);
	lua_register(m_luaState, "updateNpcIdle", NpcScriptInterface::luaUpdateNpcIdle);
	lua_register(m_luaState, "queuePlayer", NpcScriptInterface::luaQueuePlayer);
	lua_register(m_luaState, "unqueuePlayer", NpcScriptInterface::luaUnqueuePlayer);
	lua_register(m_luaState, "getQueuedPlayer", NpcScriptInterface::luaGetQueuedPlayer);
	lua_register(m_luaState, "faceCreature", NpcScriptInterface::luaFaceCreature);
}


int NpcScriptInterface::luaCreatureGetName2(lua_State *L)
{
	//creatureGetName2(name) - returns creature id
	popString(L);
	reportErrorFunc("Deprecated function.");
	lua_pushnil(L);
	return 1;
}

int NpcScriptInterface::luaCreatureGetName(lua_State *L)
{
	//creatureGetName(cid)
	popNumber(L);
	reportErrorFunc("Deprecated function. Use getCreatureName");
	lua_pushstring(L, "");
	return 1;
}

int NpcScriptInterface::luaCreatureGetPos(lua_State *L)
{
	//creatureGetPosition(cid)
	popNumber(L);
	reportErrorFunc("Deprecated function. Use getCreaturePosition");
	lua_pushnil(L);
	lua_pushnil(L);
	lua_pushnil(L);
	return 3;
}

int NpcScriptInterface::luaSelfGetPos(lua_State *L)
{
	//selfGetPosition()
	ScriptEnviroment* env = getScriptEnv();
	Npc* npc = env->getNpc();
	if(npc){
		Position pos = npc->getPosition();
		lua_pushnumber(L, pos.x);
		lua_pushnumber(L, pos.y);
		lua_pushnumber(L, pos.z);
	}
	else{
		lua_pushnil(L);
		lua_pushnil(L);
		lua_pushnil(L);
	}

	return 3;
}

int NpcScriptInterface::luaActionSay(lua_State* L)
{
    //selfSay(words, <optional> delay)
	int32_t parameters = lua_gettop(L);

	uint32_t delay = SCHEDULER_MINTICKS;
	if (parameters > 1) {
		delay = std::max(delay, popNumber(L));
	}

	std::string msg(popString(L));
	
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if(npc){
		npc->doSay(msg, delay);
	}

	return 0;
}

int NpcScriptInterface::luaActionMove(lua_State* L)
{
	//selfMove(direction)
	Direction dir = (Direction)popNumber(L);
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if(npc){
		npc->doMove(dir);
	}

	return 0;
}

int NpcScriptInterface::luaActionMoveTo(lua_State* L)
{
	//selfMoveTo(x,y,z)
	Position target;
	target.z = (int)popNumber(L);
	target.y = (int)popNumber(L);
	target.x = (int)popNumber(L);

	ScriptEnviroment* env = getScriptEnv();
	Npc* npc = env->getNpc();
	if(npc){
		npc->doMoveTo(target);
	}

	return 0;
}

int NpcScriptInterface::luaActionTurn(lua_State* L)
{
	//selfTurn(direction)
	Direction dir = (Direction)popNumber(L);

	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if(npc){
		npc->doTurn(dir);
	}

	return 0;
}

int NpcScriptInterface::luaActionFollow(lua_State* L)
{
	//selfFollow(cid)
	uint32_t cid = popNumber(L);

	ScriptEnviroment* env = getScriptEnv();

	Player* player = env->getPlayerByUID(cid);
	if(cid != 0 && !player){
		lua_pushboolean(L, false);
		return 1;
	}

	Npc* npc = env->getNpc();
	if(!npc){
		lua_pushboolean(L, false);
		return 1;
	}

	bool result = npc->setFollowCreature(player, true);
	lua_pushboolean(L, result);
	return 1;
}

int NpcScriptInterface::luaGetDistanceTo(lua_State *L)
{
	//getDistanceTo(uid)
	uint32_t uid = popNumber(L);

	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	Thing* thing = env->getThingByUID(uid);
	if(thing && npc){
		Position thing_pos = thing->getPosition();
		Position npc_pos = npc->getPosition();
		if(npc_pos.z != thing_pos.z){
			lua_pushnumber(L, -1);
		}
		else{
			int32_t dist = std::max(std::abs(npc_pos.x - thing_pos.x), std::abs(npc_pos.y - thing_pos.y));
			lua_pushnumber(L, dist);
		}
	}
	else{
		reportErrorFunc(getErrorDesc(LUA_ERROR_THING_NOT_FOUND));
		lua_pushnil(L);
	}

	return 1;
}

int NpcScriptInterface::luaGetNpcPos(lua_State* L)
{
	//getNpcPos()
	ScriptEnviroment* env = getScriptEnv();

	Position pos(0, 0, 0);
	uint32_t stackpos = 0;

	Npc* npc = env->getNpc();
	if(npc){
		pos = npc->getPosition();
		stackpos = npc->getParent()->__getIndexOfThing(npc);
	}

	pushPosition(L, pos, stackpos);
	return 1;
}

int NpcScriptInterface::luaGetNpcCid(lua_State* L)
{
	//getNpcCid()
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if(npc){
		uint32_t cid = env->addThing(npc);
		lua_pushnumber(L, cid);
	}
	else{
		lua_pushnil(L);
	}

	return 1;
}

int NpcScriptInterface::luaGetNpcName(lua_State* L)
{
	//getNpcName()
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if(npc){
		lua_pushstring(L, npc->getName().c_str());
	}
	else{
		lua_pushstring(L, "");
	}

	return 1;
}

int NpcScriptInterface::luaGetNpcFocus(lua_State* L)
{
	//getNpcFocus()
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		lua_pushnumber(L, npc->focusCreature);
	}

	return 1;
}

int NpcScriptInterface::luaSetNpcFocus(lua_State* L)
{
	//setNpcFocus(cid)
	uint32_t cid = popNumber(L);

	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		Creature* creature = env->getCreatureByUID(cid);
		if (creature) {
			npc->setCreatureFocus(creature);
		}
		else {
			npc->focusCreature = 0;
			npc->setWalkDelay(std::time(unsigned(NULL)) + 5);
		}
	}

	return 1;
}

int NpcScriptInterface::luaIsNpcIdle(lua_State *L)
{
	// isNpcIdle()
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		lua_pushboolean(L, npc->isIdle());
	}

	return 1;
}

int NpcScriptInterface::luaResetNpcIdle(lua_State *L)
{
	// resetNpcIdle()
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		npc->resetIdle();
	}

	return 1;
}

int NpcScriptInterface::luaUpdateNpcIdle(lua_State *L)
{
	// updateNpcIdle()
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		npc->updateIdle();
	}

	return 1;
}

int NpcScriptInterface::luaQueuePlayer(lua_State *L)
{
	// queuePlayer(cid)
	uint32_t cid = popNumber(L);

	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		Creature* creature = env->getCreatureByUID(cid);
		if (creature) {
			npc->queueList.push_back(cid);
		}
	}

	return 1;
}

int NpcScriptInterface::luaUnqueuePlayer(lua_State *L)
{
	// unqueuePlayer(cid)
	uint32_t cid = popNumber(L);

	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		Creature* creature = env->getCreatureByUID(cid);
		if (creature) {
			npc->queueList.remove(cid);
		}
	}

	return 1;
}

int NpcScriptInterface::luaGetQueuedPlayer(lua_State *L)
{
	// getQueuedPlayer()
	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		if (npc->queueList.empty()) {
			lua_pushnil(L);
			return 0;
		}

		Creature* creature = env->getCreatureByUID(npc->queueList.front());
		if (creature) {
			lua_pushnumber(L, creature->getID());
			npc->queueList.pop_front();
		}
	}

	return 1;
}

int NpcScriptInterface::luaFaceCreature(lua_State *L)
{
	// facePlayer(cid)
	uint32_t cid = popNumber(L);

	ScriptEnviroment* env = getScriptEnv();

	Npc* npc = env->getNpc();
	if (npc) {
		Creature* creature = env->getCreatureByUID(cid);
		if (creature) {
			g_game.internalCreatureTurn(npc, npc->getDir(creature));
		}
	}

	return 1;
}

NpcEventsHandler::NpcEventsHandler(Npc* npc)
{
	m_npc = npc;
	m_loaded = false;
}

NpcEventsHandler::~NpcEventsHandler()
{
	//
}

bool NpcEventsHandler::isLoaded()
{
	return m_loaded;
}


NpcScript::NpcScript(std::string file, Npc* npc) :
NpcEventsHandler(npc)
{
	m_scriptInterface = npc->getScriptInterface();

	if(m_scriptInterface->reserveScriptEnv()){
		m_scriptInterface->getScriptEnv()->setNpc(npc);
		if(m_scriptInterface->loadFile(file, false) == -1){
			std::cout << "Warning: [NpcScript::NpcScript] Can not load script. " << file << std::endl;
			std::cout << m_scriptInterface->getLastLuaError() << std::endl;
			m_loaded = false;
			m_scriptInterface->releaseScriptEnv();
			return;
		}

		m_scriptInterface->releaseScriptEnv();
	}

	m_onCreatureSay = m_scriptInterface->getEvent("onCreatureSay");
	m_onCreatureDisappear = m_scriptInterface->getEvent("onCreatureDisappear");
	m_onCreatureAppear = m_scriptInterface->getEvent("onCreatureAppear");
	m_onCreatureMove = m_scriptInterface->getEvent("onCreatureMove");
	m_onThink = m_scriptInterface->getEvent("onThink");
	m_loaded = true;
}

NpcScript::~NpcScript()
{
	//
}

void NpcScript::onCreatureAppear(const Creature* creature)
{
	if(m_onCreatureAppear == -1){
		return;
	}
	//onCreatureAppear(cid)
	if(m_scriptInterface->reserveScriptEnv()){
		ScriptEnviroment* env = m_scriptInterface->getScriptEnv();

		#ifdef __DEBUG_LUASCRIPTS__
		std::stringstream desc;
		desc << "npc " << m_npc->getName();
		env->setEventDesc(desc.str());
		#endif

		lua_State* L = m_scriptInterface->getLuaState();

		env->setScriptId(m_onCreatureAppear, m_scriptInterface);
		env->setRealPos(m_npc->getPosition());
		env->setNpc(m_npc);

		uint32_t cid = env->addThing(const_cast<Creature*>(creature));

		m_scriptInterface->pushFunction(m_onCreatureAppear);
		lua_pushnumber(L, cid);
		m_scriptInterface->callFunction(1);
		m_scriptInterface->releaseScriptEnv();
	}
	else{
		std::cout << "[Error] Call stack overflow. NpcScript::onCreatureAppear" << std::endl;
	}
}

void NpcScript::onCreatureDisappear(const Creature* creature)
{
	if(m_onCreatureDisappear == -1){
		return;
	}
	//onCreatureDisappear(cid)
	if(m_scriptInterface->reserveScriptEnv()){
		ScriptEnviroment* env = m_scriptInterface->getScriptEnv();

		#ifdef __DEBUG_LUASCRIPTS__
		std::stringstream desc;
		desc << "npc " << m_npc->getName();
		env->setEventDesc(desc.str());
		#endif

		lua_State* L = m_scriptInterface->getLuaState();

		env->setScriptId(m_onCreatureDisappear, m_scriptInterface);
		env->setRealPos(m_npc->getPosition());
		env->setNpc(m_npc);

		uint32_t cid = env->addThing(const_cast<Creature*>(creature));

		m_scriptInterface->pushFunction(m_onCreatureDisappear);
		lua_pushnumber(L, cid);
		m_scriptInterface->callFunction(1);
		m_scriptInterface->releaseScriptEnv();
	}
	else{
		std::cout << "[Error] Call stack overflow. NpcScript::onCreatureDisappear" << std::endl;
	}
}

void NpcScript::onCreatureMove(const Creature* creature, const Position& oldPos, const Position& newPos)
{
	if(m_onCreatureMove == -1){
		return;
	}
	//onCreatureMove(cid, oldPos, newPos)
	if(m_scriptInterface->reserveScriptEnv()){
		ScriptEnviroment* env = m_scriptInterface->getScriptEnv();

		#ifdef __DEBUG_LUASCRIPTS__
		std::stringstream desc;
		desc << "npc " << m_npc->getName();
		env->setEventDesc(desc.str());
		#endif

		lua_State* L = m_scriptInterface->getLuaState();

		env->setScriptId(m_onCreatureMove, m_scriptInterface);
		env->setRealPos(m_npc->getPosition());
		env->setNpc(m_npc);

		uint32_t cid = env->addThing(const_cast<Creature*>(creature));

		m_scriptInterface->pushFunction(m_onCreatureMove);
		lua_pushnumber(L, cid);
		LuaScriptInterface::pushPosition(L, oldPos, 0);
		LuaScriptInterface::pushPosition(L, newPos, 0);
		m_scriptInterface->callFunction(3);
		m_scriptInterface->releaseScriptEnv();
	}
	else{
		std::cout << "[Error] Call stack overflow. NpcScript::onCreatureMove" << std::endl;
	}
}

void NpcScript::onCreatureSay(const Creature* creature, SpeakClasses type, const std::string& text)
{
	if(m_onCreatureSay == -1){
		return;
	}
	//onCreatureSay(cid, type, msg)
	if(m_scriptInterface->reserveScriptEnv()){
		ScriptEnviroment* env = m_scriptInterface->getScriptEnv();

		#ifdef __DEBUG_LUASCRIPTS__
		std::stringstream desc;
		desc << "npc " << m_npc->getName();
		env->setEventDesc(desc.str());
		#endif

		env->setScriptId(m_onCreatureSay, m_scriptInterface);
		env->setRealPos(m_npc->getPosition());
		env->setNpc(m_npc);

		uint32_t cid = env->addThing(const_cast<Creature*>(creature));

		lua_State* L = m_scriptInterface->getLuaState();
		m_scriptInterface->pushFunction(m_onCreatureSay);
		lua_pushnumber(L, cid);
		lua_pushnumber(L, type);
		lua_pushstring(L, text.c_str());
		m_scriptInterface->callFunction(3);
		m_scriptInterface->releaseScriptEnv();
	}
	else{
		std::cout << "[Error] Call stack overflow. NpcScript::onCreatureSay" << std::endl;
	}
}

void NpcScript::onThink()
{
	if(m_onThink == -1){
		return;
	}
	//onThink()
	if(m_scriptInterface->reserveScriptEnv()){
		ScriptEnviroment* env = m_scriptInterface->getScriptEnv();

		#ifdef __DEBUG_LUASCRIPTS__
		std::stringstream desc;
		desc << "npc " << m_npc->getName();
		env->setEventDesc(desc.str());
		#endif

		env->setScriptId(m_onThink, m_scriptInterface);
		env->setRealPos(m_npc->getPosition());
		env->setNpc(m_npc);

		m_scriptInterface->pushFunction(m_onThink);
		m_scriptInterface->callFunction(0);
		m_scriptInterface->releaseScriptEnv();
	}
	else{
		std::cout << "[Error] Call stack overflow. NpcScript::onThink" << std::endl;
	}
}
