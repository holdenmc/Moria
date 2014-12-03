/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
dungeon.h - specific instance of a map, user can fight monsters etc. and earn
  gold and exp or die
 */

#ifndef DUNGEON_H
#define DUNGEON_H

#include <vector>
#include "map.h"
#include "player.h"
#include "monster.h"

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
#define ONE_MONSTERS 5
#define TWO_MONSTERS 7
#define THREE_MONSTERS 5
#define FOUR_MONSTERS 4
#define FIVE_MONSTERS 7
#define SIX_MONSTERS 6
#define NUM_WEAK_MONS 4
#define WEAK_MONS_MIN 0
#define NUM_MED_MONS 5
#define MED_MONS_MIN 4
#define NUM_HIGH_MONS 4
#define HIGH_MONS_MIN 9
#define BOSS_MIN 13
#define GOLD_CONST 50


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
    vector<Monster*> monsters;
    //for when you are done with the dungeon, call this to delete monsters
    void deleteMonsters();
    //given w a s d, performs an action in the corresponding direction - if the
    //space is empty, causes movement, etc.
    //similar to same method in Town but specialized for dungeons
    //difference: returns true if user opts to go back up stairs
    //difference: lets monsters move IF the user moves
    bool performActionInDirection(char direction);
    //similar to getStoreFromDoor in Town, checks w a s d direction and returns
    //the monster in that immediate direction if it exists; NULL otherwise
    Monster* getMonsterInDirection(char direction);
    //to be called if user moves to empty space '.'; takes every monster
    //except boss and moves it towards the player or attacks if directly 
    //neighboring the player
    // -> monsters break through rocks :) and move diagonally a lot :)
    void moveMonsters();
    //makes the next level of the dungeon - called when user finishes current
    //dungon - max 6 levels of dungeons
    //returns NULL if this is the 6th level of a dungeon
    Dungeon* next();
    //helper method to scatter random rock clumps on dungeon start and give
    //player and dungeon stairs proper locations
    void setupDungeon();
    //helper method to place monsters - depends on the Dungeon's level
    void spawnMonsters();
    //spawns a weak monster, updates tiles and adds to monsters vector
    void spawnWeakMonster();
    void spawnMedMonster();
    void spawnHighMonster();
    void spawnBoss(); //based on current level of dungeon
    //takes the result from thePlayer->battleMonster() as code and processes how
    //the game should look given that player or monster may or may not have died
    //assumes code is 0, 1, or 2, and theMonster is the monster that the player
    //just battled
    void processBattleResult(int code, Monster* theMonster);
};


#endif