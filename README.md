Avesta
======

open source old school server

Based on Avesta rev. 9.4.2012 (April 2012)

Protocols: 7.4, 7.6 & 7.7

The default protocol is 7.4
For 7.6 compile with definition __PROTOCOL_76__
For 7.7 compile with definition __PROTOCOL_77__

Revnetsys

Redesigned IO model using asynchronous sockets (Boost::asio)


Revbattlesys

New Formula of Armor/Defense
Weapons configurable in XML and Lua
Wands, Rods, Burst Arrows and Poison Arrows
Drunk and Paralyze System
Creatures can move diagonally
New Lua Interface (Actions, NPCs)
Big Changes in Spells
New Decay System
Rings and Amulets
New Monster AI
Vocations configurable in XML
Players can summon monsters (utevo res)
Check if the player knows the spell
Soul Points
Last Writer of letters


Revdbsys

XML as database removed
Code cleaned up
Flexible interface for database drivers
Transparent database drivers
Speed up
Much less memory used (even 1000 times less for database queries!)
Code optimization
GCC 4.2 compatibility


And

Skull System
Party System
Bed System
Save System
Mute System
Rule Violations Report system (ctrl + r)
Bug report system (ctrl + z)
Violation window system (ctrl + y)
Walk to item
Push, death, walk delays
Magic effect displayed on air
Wildcard~ for spells with params
GM Invisible (temporary removed, caused debugs)
Bursts missing target
many many more...
