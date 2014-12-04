todo:
  cleanup memory
  add DUNGEON and MONSTERS to README
  remove magic numbers
  unequipping something that adds to health/cons does not lower health (does lower max health though?)
  ->unequipping removes a health pot???????
  if you buy something from a store it removes itself, but then when you back in the store it is still there


PREMISE
Moria is a text-based ASCII RPG game, modeled after a game of the same name produced
in 1994. Your goal is to kill the Balrog at the lowest level (6th) of the dungeon.
Death is permanent.  Are you ready? 

PLAYER CREATION

You will first be prompted for your name, gender and age.

Gender affects stats slightly (males have more constitution and females have more dexterity)
Name and age don't.

You will then have randomized rolls for your main attributes (height and weight are just for show).
STR - affects damage the player deals
INT - Does nothing
DEX - affects dodge rate
CONS - affects total health and damage dealt to player
CHAR - Lowers store prices

TIP: STR and CONS matter a lot more than the others.  We didn't spend much (if any) time balancing the game.

When you're satisfied with your rolls we can move on.

OTHER STATS
HP - your health, HPots increase it by 10, but never over its max
Mana - does nothing
HPots - number of current health potions


CONTROLS

in town: 
  q to quit a store menu
  q to quit inventory
  i to view inventory

in dungeon:
  No unique controls


anywhere (not in a menu):
  Q to quit game (you lose)
  h to drink a health potion (if you have any)
  wasd to move character (when not in menu)
  numbers/letters if prompted (when leveling up, making character, etc.)
  move "into"/towards something to interact with it - if door is neighboring on
    left, a lets you shop at that store; if a monster is directly above you,
    w initiates combat


TOWN INTERFACE

The town consists of three stores and a dungeon entrance.

General Store ('g') - Sells health potions.  That's it.

Armory ('a') - sells head, leg and body armor.

Smith ('s') - Sells weapons and shields.  LaserGun is highly recommended. Pew Pew lasers!!!

SHOP MENU
Walking into the door of a shop will trigger the shop menu.  Hit the number of the desired item to buy it.
Hit 'q' to exit the menu.  Shops are fun!

ITEMS
Items come in 5 flavors.  Head, body, legs, weapon and shield.  You can only equip one at a time.
Each has a different boost on a single stat.  For example, one item might be +2 DEXT while another is +1 STR


INVENTORY
Hitting 'i' while in town activates the inventory menu.  It works like the shop menu, except hitting a number
of an item equips or unequips that item.


Dungeon entrance ('>')
  This takes you into the dungeon.


DUNGEON


MONSTERS








FUTURE IMPROVEMENTS
  make inventory viewable in dungeon
  make exp harder to earn if you are fighting low level monsters and you are higher level, and vice versa to reward fighting monsters that are stronger
