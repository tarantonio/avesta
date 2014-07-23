local TUMB_ENTRANCE = 100
local MUD_HOLE = 392
	
local duration = 5 * 60000 -- 5 minutes

function onUse(cid, item, frompos, item2, topos)
	if (isInArray(MUD, item2.itemid) == TRUE) then
		if (item2.actionid == TUMB_ENTRANCE) then
			doSendMagicEffect(topos, CONST_ME_POFF)
			doTransformItem(item2.uid, MUD_HOLE)
			addEvent(__doTransformHole__, duration, {oldType = item2.itemid, pos = topos})
			return TRUE
		end
	end
	
	return FALSE
end

function __doTransformHole__(parameters)
	local thing = getTileItemById(parameters.pos, MUD_HOLE)
	local newItem = doTransformItem(thing.uid, parameters.oldType)
end 