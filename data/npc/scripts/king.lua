
_state = 0
_delay = 750

function getNext()
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

local function greet(cid, delay)
	selfSay('I greet thee, my loyal subject.', delay)
end

function onCreatureAppear(cid)
end

function onCreatureDisappear(cid)
	if (getFocus() == cid) then
		selfSay('What a lack of manners!', _delay)
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
		if (msgcontains(msg, 'king') and getDistanceToCreature(cid) <= 4) then
			if (msgcontains(msg, 'hello') or msgcontains(msg, 'hail') or msgcontains(msg, 'salutations')) then
				updateIdle()
				setFocus(cid)
				greet(cid, _delay)
			end
		end
		
	elseif (getFocus() ~= cid) then 
		if ((msgcontains(msg, 'hi') or msgcontains(msg, 'hello')) and getDistanceToCreature(cid) <= 4) then
			--selfSay('Just wait, ' .. getCreatureName(cid) .. '.', _delay)
			--queuePlayer(cid)
		end
		
	else
		if (msgcontains(msg, 'bye') or msgcontains(msg, 'farewell')) then
			selfSay('Good bye, ' .. getCreatureName(cid) .. '!', _delay)
			getNext()
		
		elseif (msgcontains(msg, 'job')) then
			_selfSay('I am your sovereign, King Tibianus III, and it\'s my duty to provide justice and guidance for my subjects.')
		
		elseif (msgcontains(msg, 'justice')) then
			_selfSay('I try my best to be just and fair to our citizens. The army and the TBI are a great help for fulfilling this duty.')
		
		elseif (msgcontains(msg, 'name')) then
			_selfSay('It\'s hard to believe that you don\'t know your own king!')
		
		elseif (msgcontains(msg, 'king') or msgcontains(msg, 'tibianus')) then
			_selfSay('The king has not much interest in magic items as far as I know.')
		
		elseif (msgcontains(msg, 'news')) then
			_selfSay('The latest news are usually brought to our magnificent town by brave adventurers. They spread tales of their journeys at Frodo\'s tavern.')
		
		elseif (msgcontains(msg, 'tibia') or msgcontains(msg, 'land')) then
			_selfSay('Soon the whole land will be ruled by me once again!')
		
		elseif (msgcontains(msg, 'how') and msgcontains(msg, 'are') and msgcontains(msg, 'you')) then
			_selfSay('Thank you, I\'m fine.')
		
		elseif (msgcontains(msg, 'castle')) then
			_selfSay('Rain Castle is my home.')
		
		elseif (msgcontains(msg, 'sell')) then
			_selfSay('Sell? Sell what? My kingdom isn\'t for sale!')
		
		elseif (msgcontains(msg, 'god')) then
			_selfSay('Honor the gods and pay your taxes.')
		
		elseif (msgcontains(msg, 'zathroth')) then
			_selfSay('Please ask a priest about the gods.')
		
		elseif (msgcontains(msg, 'citizen')) then
			_selfSay('The citizens of Tibia are my subjects. Ask the old monk Quentin to learn more about them.')
		
		elseif (msgcontains(msg, 'sam')) then
			_selfSay('He is a skilled blacksmith and a loyal subject.')
			
		elseif (msgcontains(msg, 'frodo')) then
			_selfSay('He is the owner of Frodo\'s Hut and a faithful tax-payer.')
			
		elseif (msgcontains(msg, 'gorn')) then
			_selfSay('He was once one of Tibia\'s greatest fighters. Now he is selling equipment.')
		
		elseif (msgcontains(msg, 'benjamin')) then
			_selfSay('He was once my greatest general. Now he is very old and senile but we entrusted him with work for the Royal Tibia Mail.')
		
		elseif (msgcontains(msg, 'harkath') or msgcontains(msg, 'bloodblade') or msgcontains(msg, 'general')) then
			_selfSay('Harkath Bloodblade is the general of our glorious army.')
		
		elseif (msgcontains(msg, 'noodles')) then
			_selfSay('The royal poodle Noodles is my greatest treasure!')
		
		elseif (msgcontains(msg, 'ferumbras')) then
			_selfSay('He is a follower of the evil god Zathroth and responsible for many attacks on us. Kill him on sight!')
			
		elseif (msgcontains(msg, 'bozo')) then
			_selfSay('He is my royal jester and cheers me up now and then.')
			
		elseif (msgcontains(msg, 'treasure')) then
			_selfSay('The royal poodle Noodles is my greatest treasure!')
			
		elseif (msgcontains(msg, 'monster')) then
			_selfSay('o and hunt them! For king and country!')
			
		elseif (msgcontains(msg, 'help')) then
			_selfSay('Visit Quentin, the monk, for help.')
			
		elseif (msgcontains(msg, 'quest') or msgcontains(msg, 'mission')) then
			_selfSay('I will call for heroes as soon as the need arises again and then reward them appropriately.')
			
		elseif (msgcontains(msg, 'gold') or msgcontains(msg, 'money') or msgcontains(msg, 'tax')) then
			_selfSay('To pay your taxes, visit the royal tax collector.')
			
		elseif (msgcontains(msg, 'sewer')) then
			_selfSay('What a disgusting topic!')
			
		elseif (msgcontains(msg, 'dungeon')) then
			_selfSay('Dungeons are no places for kings.')
			
		elseif (msgcontains(msg, 'equipment')) then
			_selfSay('Feel free to buy it in our town\'s fine shops.')
			
		elseif (msgcontains(msg, 'food')) then
			_selfSay('Ask the royal cook for some food.')
			
		elseif (msgcontains(msg, 'time') or msgcontains(msg, 'hero') or msgcontains(msg, 'heroes')) then
			_selfSay('It\'s a time for heroes, that\'s for sure!')
			
		elseif (msgcontains(msg, 'tax') and msgcontains(msg, 'collector')) then
			_selfSay('He has been lazy lately. I bet you have not payed any taxes at all.')
			
		elseif (msgcontains(msg, 'king')) then
			_selfSay('I am the king, so mind your words!')
			
		elseif (msgcontains(msg, 'army')) then
			_selfSay('Ask the soldiers about that topic.')
			
		elseif (msgcontains(msg, 'enemy') or msgcontains(msg, 'enemies')) then
			_selfSay('Our enemies are numerous. The evil minotaurs, Ferumbras, and the renegade city of Carlin to the north are just some of them.')
			
		elseif ((msgcontains(msg, 'city') and msgcontains(msg, 'north')) or msgcontains(msg, 'carliin')) then
			_selfSay('They dare to reject my reign over the whole continent!')
			
		elseif (msgcontains(msg, 'thais') or msgcontains(msg, 'city')) then
			_selfSay('Our beloved city has some fine shops, guildhouses, and a modern system of sewers.')
			
		elseif (msgcontains(msg, 'shop')) then
			_selfSay('Visit the shops of our merchants and craftsmen.')
			
		elseif (msgcontains(msg, 'merchant') or msgcontains(msg, 'craftsmen')) then
			_selfSay('Ask around about them.')
			
		elseif (msgcontains(msg, 'guild')) then
			_selfSay('The four major guilds are the knights, the paladins, the druids, and the sorcerers.')
			
		elseif (msgcontains(msg, 'minotaur')) then
			_selfSay('Vile monsters, but I must admit they are strong and sometimes even cunning ... in their own bestial way.')
			
		elseif (msgcontains(msg, 'paladin') or msgcontains(msg, 'elane')) then
			_selfSay('The paladins are great protectors for Thais.')
			
		elseif (msgcontains(msg, 'knight') or msgcontains(msg, 'gregor')) then
			_selfSay('The brave knights are necessary for human survival in Thais.')
			
		elseif (msgcontains(msg, 'sorcerer') or msgcontains(msg, 'muriel')) then
			_selfSay('The magic of the sorcerers is a powerful tool to smite our enemies.')
			
		elseif (msgcontains(msg, 'druid') or msgcontains(msg, 'marvik')) then
			_selfSay('We need the druidic healing powers to fight evil.')
			
		elseif (msgcontains(msg, 'good')) then
			_selfSay('The forces of good are hard pressed in these dark times.')
			
		elseif (msgcontains(msg, 'evil')) then
			_selfSay('We need all strength we can muster to smite evil!')
			
		elseif (msgcontains(msg, 'order')) then
			_selfSay('We need order to survive!')
			
		elseif (msgcontains(msg, 'chaos')) then
			_selfSay('Chaos arises from selfishness, and that\'s its weakness.')
			
		elseif (msgcontains(msg, 'excalibug')) then
			_selfSay('It\'s the sword of the kings. If you could return this weapon to me I would reward you beyond your dreams.')
			
		elseif (msgcontains(msg, 'reward')) then
			_selfSay('Well, if you want a reward, go on a quest to bring me Excalibug!')
			
		elseif (msgcontains(msg, 'chester')) then
			_selfSay('A very competent person. A little nervous but very competent.')
			
		elseif (msgcontains(msg, 'eremo')) then
			_selfSay('It is said that he lives on a small island near Edron. Maybe the people there know more about him.')
			
		elseif (msgcontains(msg, 'tbi')) then
			_selfSay('This organisation is important in holding our enemies in check. Its headquarter is located in the bastion in the northwall.')
			
		elseif (msgcontains(msg, 'promote') or msgcontains(msg, 'promotion')) then
			_selfSay('Do you want to be promoted in your vocation for 20000 gold?')
			_state = 1
		
		elseif (_state == 1) then
			if (msgcontains(msg, 'yes')) then
				if (isPremium(cid) == 1) then
					if (isPromoted(cid) == 0) then
						if (getPlayerLevel(cid) >= 20) then
							if (doPlayerRemoveMoney(cid, 20000) == 1) then
								doPlayerSetVocation(cid, getPlayerVocation(cid) + 4)
								_selfSay('Congratulations! You are now promoted. Visit the sage Eremo for new spells.')
							else
								_selfSay('You do not have enough money.')
							end
						else
							_selfSay('You need to be at least level 20 in order to be promoted.')
						end
					else
						_selfSay('You are already promoted.')
					end
				else
					_selfSay('You need a premium account in order to promote.')
				end
			else
				_selfSay('Ok, then not.')
			end
			
			_state = 0
		end
	end
end

function onThink()
	if (getFocus() ~= 0) then
		if (isIdle() or getDistanceToCreature(getFocus()) > 4) then
			selfSay('What a lack of manners!', _delay)
			getNext()
		end
	end
end


