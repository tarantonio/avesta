
_state = 0
_delay = 750

function getNext()
	_state = 0
	
	nextPlayer = getQueuedPlayer()
	if (nextPlayer ~= nil) then
		if (getDistanceToCreature(nextPlayer) <= 4) then
			setFocus(nextPlayer)
			greet(nextPlayer, _delay * 2)
			updateIdle()
			return
		else
			getNext()
		end
	end
	
	setFocus(0)
	resetIdle()
end

function _selfSay(message)
	selfSay(message, _delay)
	updateIdle()
end

function selfSay_(message)
	selfSay(message, _delay)
	getNext()
end

function onCreatureAppear(cid)
end

function onCreatureDisappear(cid)
	if (getFocus() == cid) then
		selfSay('See you.', _delay)
		getNext()
	else
		unqueuePlayer(cid)
	end
end

function onCreatureMove(cid, oldPos, newPos)
	if (getFocus() == cid) then
		faceCreature(cid)
	end
end

local function greet(cid, delay)
	if (isDruid(cid) == TRUE) then
		selfSay('Hail, friend of nature! How may I help you?', delay)
		
	elseif (isKnight(cid) == TRUE) then
		selfSay('Another creature who believes thinks physical strength is more important than wisdom! Why are you disturbing me?', delay)
		
	elseif (isSorcerer(cid) == TRUE) then
		selfSay('It\'s good to see somebody who has chosen the path of wisdom. What do you want?', delay)
		
	elseif (isPaladin(cid) == TRUE) then
		selfSay('Neither strong enough to be a knight nor wise enough to be a real mage. You like it easy, don\'t you? Why are you disturbing me?', delay)
	end
end

function onCreatureSay(cid, type, msg)
	if (getFocus() == 0) then
		if ((msgcontains(msg, 'hi') or msgcontains(msg, 'hello')) and getDistanceToCreature(cid) <= 4) then
			if (getPlayerLevel(cid) < 15) then
				selfSay('I don\'t talk to little children!!', _delay)
			else
				updateIdle()
				setFocus(cid)
				greet(cid, _delay)
			end
		end
		
	elseif (getFocus() ~= cid) then 
		if ((msgcontains(msg, 'hi') or msgcontains(msg, 'hello')) and getDistanceToCreature(cid) <= 4) then
			selfSay('Silence, unworthy creature!', _delay)
			if (getPlayerLevel(cid) >= 15) then
				queuePlayer(cid)
			end
		end
		
	else
		if (msgcontains(msg, 'bye') or msgcontains(msg, 'farewell')) then
			selfSay('Farewell, ' .. getCreatureName(cid) .. '!', _delay)
			getNext()
		
		elseif (msgcontains(msg, 'name')) then
			_selfSay('I am Skjaar the Mage, master of all spells.')
		
		elseif (msgcontains(msg, 'job')) then
			_selfSay('Once I was the master of all mages, but now I only protect this crypt.')
		
		elseif (msgcontains(msg, 'door')) then
			_selfSay('This door seals a crypt.')
		
		elseif (msgcontains(msg, 'crypt')) then
			_selfSay('Here lies my master. Only his closest followers may enter.')
		
		elseif (msgcontains(msg, 'help')) then
			_selfSay('I\'m not here to help anybody. I only protect my master\'s crypt.')
		
		elseif (msgcontains(msg, 'mountain')) then
			_selfSay('Hundreds of years my master\'s castle stood on the top of this mountain. Now there is a volcano.')
		
		elseif (msgcontains(msg, 'volcano')) then
			_selfSay('I can still feel the magical energy in the volcano.')
		
		elseif (msgcontains(msg, 'castle')) then
			_selfSay('The castle was destroyed when my master tried to summon a nameless creature. All that is left is this volcano.')
		
		elseif (msgcontains(msg, 'time')) then
			_selfSay('To those who have lived for a thousand years time holds no more terror.')
		
		elseif (msgcontains(msg, 'master')) then
			_selfSay('If you are one of his followers, you need not ask about him, for you will know. And if you aren\'t, you are not worthy anyway!')
		
		elseif (msgcontains(msg, 'key')) then
			_selfSay('I will give the key to the crypt only to the closest followers of my master. Would you like me to test you?')
			_state = 1
			
		elseif (_state == 1) then
			if (msgcontains(msg, 'yes')) then
				_selfSay('Before we start I must ask you for a small donation of 1000 gold coins. Are you willing to pay 1000 gold coins for the test?')
				_state = 2
				
			elseif (msgcontains(msg, 'no')) then
				selfSay_('Then leave, unworthy worm!')
			else
				selfSay_('You\'re not worthy if you cannot make up your mind. Leave!')
			end
			
		elseif (_state == 2) then
			if (msgcontains(msg, 'yes')) then
				if (doPlayerRemoveMoney(cid, 1000)) then
					_selfSay('All right then. Here comes the first question. What was the name of Dago\'s favourite pet?')
					_state = 3
				else
					selfSay_('You don\'t even have the money to make a donation? Then go!')
				end
			
			elseif (msgcontains(msg, 'no')) then
				selfSay_('You\'re not worthy then. Now leave!')
				
			else
				selfSay_('You\'re not worthy if you cannot make up your mind. Leave!')
			end
			
		elseif (_state == 3) then
			if (msgcontains(msg, 'redips')) then
				_selfSay('Perhaps you knew him after all. Tell me - how many fingers did he have when he died?')
				_state = 4
			else
				selfSay_('You are wrong. Get lost!')
			end
		
		elseif (_state == 4) then
			if (msgcontains(msg, '7') or msgcontains(msg, 'seven')) then
				_selfSay('Also true. But can you also tell me the colour of the deamons in which master specialized?')
				_state = 5
			else
				selfSay_('You are wrong. Get lost!')
			end
			
		elseif (_state == 5) then
			if (msgcontains(msg, 'black')) then
				_selfSay('It seems you are worthy after all. Do you want the key to the crypt?')
				_state = 6
			else
				selfSay_('You are wrong. Get lost!')
			end
			
		elseif (_state == 6) then
			if (msgcontains(msg, 'yes')) then
				_selfSay('Here you are.')
				item = doPlayerAddItem(cid, 2089)
				doSetItemActionId(item, 3142)
			else
				selfSay('It is always a wise decision to leave the dead alone.', _delay)
			end
		
		elseif (msgcontains(msg, 'idiot') or msgcontains(msg, 'fuck') or msgcontains(msg, 'asshole')) then
			selfSay_('Take this for your words!')
			doPlayerAddHealth(cid, -(getPlayerHealth(cid) - 1))
			doSendMagicEffect(getCreaturePosition(cid), CONST_ME_FIREAREA)
		end
	end
end

function onThink()
	if (getFocus() ~= 0) then
		if (isIdle() or getDistanceToCreature(getFocus()) > 4) then
			selfSay('Run away, unworthy ' .. getCreatureName(getFocus()) .. '!', _delay)
			getNext()
		end
	end
end


