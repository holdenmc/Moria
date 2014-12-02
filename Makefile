#
# File:   Makefile
# Author: Conor Ryan, Holden McGinnis
# Desc:   Makefile for Fall 2014 CIS 190 Final Project
#

moria: main.o player.o utils.o town.o store.o map.o dungeon.o item.o monster.o
	g++ main.o player.o utils.o town.o store.o map.o dungeon.o item.o monster.o -o moria

# rules to compile the individual .o files
main.o: main.cpp
	g++ -c -Wall main.cpp
player.o: player.cpp
	g++ -c -Wall player.cpp
utils.o: utils.cpp
	g++ -c -Wall utils.cpp
town.o: town.cpp
	g++ -c -Wall town.cpp
store.o: store.cpp
	g++ -c -Wall store.cpp
map.o: map.cpp
	g++ -c -Wall map.cpp
dungeon.o: dungeon.cpp
	g++ -c -Wall dungeon.cpp
item.o: item.cpp
	g++ -c -Wall item.cpp
monster.o: monster.cpp
	g++ -c -Wall monster.cpp


########################################
# rules for cleaning away excess files #
########################################

# removes .o and executable files
clean:
	rm  -f main.o player.o utils.o town.o store.o map.o dungeon.o moria 

# removes any temporary (~) files
cleaner: 
	rm  -f *~

# runs both clean and cleaner
cleanest: clean cleaner

