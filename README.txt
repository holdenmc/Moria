todo:
  cleanup memory
    ->delete the stores items made vector etc at end of main()?
  finish this readme
    ->add DUNGEON and MONSTERS to README
  if you buy something from a store it removes itself, but then when you back in the store it is still there



PREMISE
Moria is a text-based ASCII RPG game, modeled after a game of the same name produced
in 1994. Your goal is to kill the Balrog at the lowest level (6th) of the dungeon.
Death is permanent.  Are you ready? 

PLAYER CREATION

You will first be prompted for your name, gender and age.

Gender affects stats slightly (males have more constitution and females have
more dexterity)
Name and age do not affect stats.

You will then have randomized rolls for your main attributes (height and weight
are just for show).
STR - affects damage the player deals
INT - Does nothing
DEX - affects dodge rate (if you fight a monster and take no damage but it lives, you dodged its attack)
CONS - affects total health and damage dealt to player
CHAR - Lowers store prices

TIP: STR and CONS matter a lot more than the others.  We didn't spend much
(if any) time balancing the game. The main idea is that things are stronger than
you, so you should spend some time leveling up and also losing repeatedly.

When you're satisfied with your rolls we can move on.

OTHER STATS
HP - your health, HPots increase it by 10, but never over its max
Mana - does nothing
HPots - number of current health potions



CONTROLS
In town: 
  q to quit a store menu
  q to quit inventory
  i to view inventory

In dungeon:
  No unique controls

Anywhere (not in a menu):
  Q to quit game (you lose)
  h to drink a health potion (if you have any)
  wasd to move character
  numbers/letters if prompted (when leveling up, making character, etc.)
  move "into"/towards something to interact with it - if door is neighboring on
    left, a lets you shop at that store; if a monster is directly above you,
    w initiates combat


MAP superclass
Map is the superclass of Town and Dungeon, as they both share very similar base
features. In particular, each one stores the instance of the 'Player' object,
and has its status represented by a 2D array of char's. Additionally,
each keeps track of where the player is at all times (the player does not keep
track of this information).


TOWN INTERFACE
The town consists of three stores and a dungeon entrance:
  General Store ('g') - Sells health potions.  That's it.
  Armory ('a') - sells head, leg and body armor.
  Smith ('s') - sells weapons and shields.  LaserGun is highly recommended. Pew
    Pew lasers!!!
  Dungeon entrance ('>') -  takes you into the dungeon.


SHOP MENU
Walking into the door of a shop will trigger the shop menu.  Hit the number of
the desired item to buy it.
Hit 'q' to exit the menu.  Shops are fun!


ITEMS
Items come in 5 flavors.  Head, body, legs, weapon and shield.  You can only
equip one at a time.
Each has a different boost on a single stat.  For example, one item might be 
+2 DEXT while another is +1 STR


INVENTORY
Hitting 'i' while in town activates the inventory menu.  It works like the shop
menu, except hitting a number
of an item equips or unequips that item.


DUNGEON
There are six dungeons, each of which is accessed from the previous level.
They increase in difficulty very quickly. In order to reach the next dungeon
from the current dungeon, the player must kill all of the monsters in the
current dungeon, at which point the rocks surrounding the entrance will go away.

Every dungeon is randomly generated with 1) rocks and 2) monsters (to an 
extent). There are variable number of rock clusters with varying sizes, and each
level of the dungeon has a predefined assortment of monster 'levels'. That is,
dungeons with level x are guaranteed to always have a certain number of low,
medium, and high level monsters in them. The actual monsters that satisfy these
difficulties are random (i.e., you would always have X medium monsters but you
will see a different assortment of characters since their identities are
random).

Dungeon traversal works through the next() function, which takes the current
dungeon level and creates a randomly generated dungeon of the next level. The
player is then thrown into this dungeon until they decide to 1) go to the next
dungeon or 2) go to the previous dungeon. The end result: the player can access
dungeons of LOWER level (easier ones) if they are in a deep dungeon by just
going back up stairs, which will be the same dungeon that was cleared on entry.
HOWEVER, the player cannot return to a deeper level dungeon - i.e., if you are
on level 1, descend to level 2, beat all the monsters, go upstairs, and go back
downstairs, you have the beat a newly generated level 2.

To win the game, the player must traverse all 6 levels and kill every monster
and boss.

While in the dungeon, the player cannot open their inventory and change weapons
or armor. Whenever the player moves, all of the monsters move. There is a battle
mechanic such that if the player moves INTO the monster, the player attacks
first and might kill the monster before it can attack. Similarly, if the monster
moves into the player on its turn, it attacks first. If the player attacks,
the other monsters wait and watch the battle before they attack (monsters only
initiate damage if the player MOVES). Note that since monsters can move
diagonally, this is like 2 'moves', so the monster may attack the player if the 
player is right next to the monster and moves up or down.


MONSTERS
In the dungeon there are monsters, all of which are carefully calculated. There
are 3 'levels' of monster: low, medium, and high. Whenever a low level monster
is spawned, it chooses from any variety of low level monster, and gives it
random stats (that are characteristic of a low level monster). Functionally,
every monster acts the same, some are just stronger than others.

There are also 6 'boss' monsters, one for every level of the dungeon. Each 
boss always spawns on its corresponding level, with the final boss being the
(very strong) Balrog. Bosses are the same every time - they always have the
same stats.

Monster movement is very predictable and always the same. They can diagonally
and 'crush' rocks that are in the way (so the player cannot just keep moving
back and forth and live - the monsters will get to the player. Looking at a 
dungeon, if the player is below and to the right of the monster, it moves once
to the right, and once down (two movements). If they are directly to the right,
the monster moves once to the right, etc.

On death monsters drop the same amount of gold every time (50) and give exp
scaled to account for the monster's level and the player's level. Gold is shown
where the monster was before as a '$'. Monsters do not destroy gold (that
would be uncool).



FUTURE IMPROVEMENTS
  - make inventory viewable in dungeon
  - make monsters drop more/less gold depending on level, player level, etc.



INDIVIDUAL CONTRIBUTIONS 
  dungeon.h/cpp - conor
  item.h/cpp - holden
  main - both
  map.h/cpp - conor
  monster.h/cpp - conor
  player.h/cpp - holden
  store.h/cpp - holden
  town.h/cpp - portion relating to player movement: conor; portion relating to
    stores, menus, inventory, etc. holden
  utils.h/cpp - mostly holden (all but DrawGame and toString)