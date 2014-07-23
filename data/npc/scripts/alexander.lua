
_state = 0
_count = 0
_index = 0
_delay = 1000

items = {}
items[0] = {name = 'blank rune', id = 2260, subtype = -1, sell = 10, buy = -1}
items[1] = {name = 'life ring', id = 2168, subtype = -1, sell = 900, buy = -1}
items[2] = {name = 'crystal ball', id = 2192, subtype = -1, sell = 530, buy = 190}
items[3] = {name = 'life crystal', id = 2177, subtype = -1, sell = 900, buy = 85}
items[4] = {name = 'mind stone', id = 2178, subtype = -1, sell = 900, buy = 170}

function getNext()
	nextPlayer = getQueuedPlayer()
	if (nextPlayer ~= nil) then
		if (getDistanceToCreature(nextPlayer) <= 4) then
			updateIdle()
			setFocus(nextPlayer)
			greet(nextPlayer, _delay * 3)
			return
		else
			getNext()
		end
	end
	
	setFocus(0)
	resetIdle()
end

local function onActionItem(action)
	if ((action == 'buy' and items[_index].sell == -1) or
		(action == 'sell' and items[_index].buy == -1)) then
		return
	end
	
	amount = ''
	suffix = ''
	plural = 'a'
	
	if (_count > 1) then
		amount = ' ' .. tostring(_count)
		suffix = 's'
		plural = ''
	end
	
	cost = items[_index].buy
	if (action == 'buy') then
		cost = items[_index].sell
	end
	
	selfSay('Do you want to ' .. action .. ' ' .. plural .. amount .. ' ' .. items[_index].name .. suffix .. ' for ' .. cost .. ' gold?')
end

function _selfSay(message)
	selfSay(message, _delay)
	updateIdle()
end

local function greet(cid, delay)
	selfSay('Hi there ' .. getCreatureName(cid) .. '.', delay)
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

function onCreatureSay(cid, type, msg)
	if (getFocus() == 0) then
		if ((msgcontains(msg, 'hi') or msgcontains(msg, 'hello')) and getDistanceToCreature(cid) <= 4) then
			updateIdle()
			setFocus(cid)
			greet(cid, _delay)
		end
		
	elseif (getFocus() ~= cid) then
		if ((msgcontains(msg, 'hi') or msgcontains(msg, 'hello')) and getDistanceToCreature(cid) <= 4) then
			selfSay('Just wait, ' .. getCreatureName(cid) .. '.', _delay)
			queuePlayer(cid)
		end
		
	else
		if (msgcontains(msg, 'bye')) then
			selfSay('See you.', _delay)
			getNext()
		
		elseif (msgcontains(msg, 'name')) then
			_selfSay('I am Alexander.')
		
		elseif (msgcontains(msg, 'job')) then
			_selfSay('I trade with runes and other magic items.')
		
		elseif (msgcontains(msg, 'time')) then
			_selfSay('It\'s ' .. getTibiaTime() .. ' right now.')
		
		elseif (msgcontains(msg, 'king') or msgcontains(msg, 'tibianus')) then
			_selfSay('The king has not much interest in magic items as far as I know.')
		
		elseif (msgcontains(msg, 'army')) then
			_selfSay('The army uses weapons and armor rather then items of magic.')
		
		elseif (msgcontains(msg, 'ferumbras')) then
			_selfSay('A hero has to be well prepared to face this threat.')
		
		elseif (msgcontains(msg, 'excalibug')) then
			_selfSay('Ah, I would trade a fortune for this fabulous item.')
		
		elseif (msgcontains(msg, 'thais')) then
			_selfSay('I am glad the king founded this academy far away from the mundane troubles of Thais')
		
		elseif (msgcontains(msg, 'tibia')) then
			_selfSay('The world is filled with wonderous places and items.')
		
		elseif (msgcontains(msg, 'carlin')) then
			_selfSay('I heard it\'s a city of druids.')
		
		elseif (msgcontains(msg, 'edron')) then
			_selfSay('In our town, science and arts are thriving.')
		
		elseif (msgcontains(msg, 'news') or msgcontains(msg, 'rumors')) then
			_selfSay('Ask for news and rumors in the tavern.')
		
		elseif (msgcontains(msg, 'offer') or msgcontains(msg, 'goods')) then
			_selfSay('I\'m selling runes, life rings, wands, rods and crystal balls.')
			
		elseif (msgcontains(msg, 'rune') and not(msgcontains(msg, 'blank'))) then
			_selfSay('I sell blank runes and spell runes.')
			
		elseif (_state == 1) then
			if (msgcontains(msg, 'yes')) then
				if (doPlayerRemoveMoney(cid, items[_index].sell * _count) == 1) then
					for i = 1, _count do
						doPlayerAddItem(cid, items[_index].id, items[_index].subtype)
					end
				
					selfSay('Here you are.', _delay)
				else
					selfSay('Come back, when you have enough money.', _delay)
				end
				
				updateIdle()
			else
				selfSay('Hmm, but next time.', _delay)
			end
			
			_state = 0
			
		elseif (_state == 2) then
			if (msgcontains(msg, 'yes')) then
				if (doPlayerRemoveItem(cid, items[_index].id, _count, items[_index].subtype) == 1) then
					doPlayerAddMoney(cid, items[_index].buy * _count)
					selfSay('Ok. Here is your money.')
				else
					if (count > 1) then
						selfSay('Sorry, you do not have so many.', _delay)
					else
						selfSay('Sorry, you do not have one.', _delay)
					end
				end
				
				updateIdle()
			else
				selfSay('Maybe next time.', _delay)
			end
		
			_state = 0
			
		else
			for n = 0, table.getn(items) do
				if (msgcontains(msg, items[n].name) or msgcontains(msg, items[n].name .. "s")) then
					_count = getCount(msg)
					_index = n
					
					if (msgcontains(msg, 'sell')) then
						onActionItem('sell')
						_state = 2
					else
						onActionItem('buy')
						_state = 1
					end
					
					updateIdle()
					break
				end
			end
		end
	end
end

function onThink()
	if (getFocus() ~= 0) then
		if (isIdle() or getDistanceToCreature(getFocus()) > 4) then
			selfSay('See you.', _delay)
			getNext()
		end
	end
end


