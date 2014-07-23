-- By GriZzm0

function onUse(cid, item, frompos, item2, topos)
	-- 490 fish
	-- 491 no fish 
	-- 492 fish regeneration
	if (item2.itemid == 490) then
		fishingskill = getPlayerSkill(cid,6)
		formula = fishingskill / 200 + 0.85 * math.random()
		if formula > 0.70 then
			doTransformItem(item2.uid, 492)
			doDecayItem(item2.uid)
			doPlayerAddSkillTry(cid, 6, 2)
			doPlayerAddItem(cid,2667, 1)
		else
			doPlayerAddSkillTry(cid, 6, 1)
		end
		
		doSendMagicEffect(topos, 1)

	elseif (item2.itemid == 491 or item2.itemid == 492) then
		doSendMagicEffect(topos, 1)
	end
	
	return TRUE
end
