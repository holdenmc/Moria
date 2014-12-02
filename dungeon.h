/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
dungeon.h - specific instance of a map, user can fight monsters etc. and earn
  gold or die
 */

#ifndef DUNGEON_H
#define DUNGEON_H


#include "map.h"
#include "player.h"

#define MIN_CLUMPS 35
#define CLUMP_RANGE 10
#define MAX_ROCKS_IN_CLUMP 15
#define NUM_DIRECTIONS 4
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define PLAYER_START_ROW 10
#define PLAYER_START_COL 2
#define MAX_DUNGEONS 6

using namespace std;

class Dungeon: public Map {
  public:
    //make the first level of a dungeon specialized map instance
    Dungeon(Player* thePlayer);
    //make a dungeon with given difficulty level (ints 1 through 6)
    Dungeon(int level, Player* thePlayer);
    //enters an inner while loop which lets the player play out the game, moving
    //inside of the dungeon, etc.
    //takes a pointer to the player (as the dungeon will interact with it)
    void enterDungeonLoop();
    //advances game based on user input char - wasd etc.
    //returns 1 if user entered 'q' at valid time to end program
    bool performDungeonAction(char input);

  private:
    //1 through 6 to represent each level of dungeon (difficulty)
    int level;
    //given w a s d, performs an action in the corresponding direction - if the
    //space is empty, causes movement, etc.
    //similar to same method in Town but specialized for dungeons
    void performActionInDirection(char direction);
    //makes the next level of the dungeon - called when user finishes current
    //dungon - max 6 levels of dungeons
    //returns NULL if this is the 6th level of a dungeon
    Dungeon* next();
    //helper method to scatter random rock clumps on dungeon start and give
    //player and dungeon stairs proper locations
    void setupDungeon();
    //helper method to place monsters - depends on the Dungeon's level
    void spawnMonsters();
};


#endif