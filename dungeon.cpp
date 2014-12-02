/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
dungeon.cpp - implementation for dungeon.cpp
 */

#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "map.h"
#include "dungeon.h"
#include "player.h"
#include "utils.h"
#include "monster.h"

Dungeon::Dungeon(Player* thePlayer) {
  level = 1;
  this->thePlayer = thePlayer;

  setupDungeon();
  spawnMonsters();
}

Dungeon::Dungeon(int level, Player* thePlayer) {
  this->level = level;
  this->thePlayer = thePlayer;
  
  setupDungeon();
  spawnMonsters();
}

void Dungeon::enterDungeonLoop() {
  bool done = false;
  char input;

  while (!done) {
    DrawGame(this, thePlayer);

    cin >> input;

    done = performDungeonAction(input);
  }
}

bool Dungeon::performDungeonAction(char input) {
  //add in specific user commands besides movement here if necessary
  /*if (input == 'q') {
    return true;
  }*/

  return performActionInDirection(input);
}

void Dungeon::deleteMonsters() {
  unsigned int i;
  for (i = 0; i < monsters.size(); i++) {
    delete(monsters[i]);
  }
}

bool Dungeon::performActionInDirection(char direction) {
  if (direction == 'w') {
    //check for empty space...
    if (tiles[playerLocRow - 1][playerLocCol] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocRow--;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow - 1][playerLocCol] == '>') { //next level
      Dungeon* nextLevel = next();
      nextLevel->enterDungeonLoop();

      nextLevel->deleteMonsters();
      delete(nextLevel);
    } else if (tiles[playerLocRow - 1][playerLocCol] == '<') { //prev level
      return true;
    }
  } else if (direction == 'a') {
    if (tiles[playerLocRow][playerLocCol - 1] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocCol--;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow][playerLocCol - 1] == '>') {
      Dungeon* nextLevel = next();
      nextLevel->enterDungeonLoop();

      nextLevel->deleteMonsters();
      delete(nextLevel);
    } else if (tiles[playerLocRow][playerLocCol - 1] == '<') {
      return true;
    }
  } else if (direction == 's') {
    if (tiles[playerLocRow + 1][playerLocCol] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocRow++;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow + 1][playerLocCol] == '>') {
      Dungeon* nextLevel = next();
      nextLevel->enterDungeonLoop();

      nextLevel->deleteMonsters();
      delete(nextLevel);
    } else if (tiles[playerLocRow + 1][playerLocCol] == '<') {
      return true;
    }
  } else if (direction == 'd') {
    if (tiles[playerLocRow][playerLocCol + 1] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocCol++;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow][playerLocCol + 1] == '>') {
      Dungeon* nextLevel = next();
      nextLevel->enterDungeonLoop();

      nextLevel->deleteMonsters();
      delete(nextLevel);
    } else if (tiles[playerLocRow][playerLocCol + 1] == '<') {
      return true;
    }
  }

  return false;
}

Dungeon* Dungeon::next() {
  if (level == MAX_DUNGEONS) {
    return NULL;
  }

  return new Dungeon(level + 1, thePlayer);
}

void Dungeon::setupDungeon() {
  //place random clumps of rocks ('#') throughout - from 15 to 24, each with at
  //most 6 rocks in it (shape also random)
  //seed based on time of day for true randomness
  srand(time(NULL));
  int numClumps = rand() % CLUMP_RANGE + MIN_CLUMPS;
  int i = 0;
  while (i < numClumps) {
    int numRocks = rand() % MAX_ROCKS_IN_CLUMP + 1; //number of rocks in clump

    int row = rand() % ROWS;
    int col = rand() % COLS;
    int j = 0;
    while (j < numRocks) {
      tiles[row][col] = '#';

      //randomly choose where next rock in clump attaches
      int direction = rand() % NUM_DIRECTIONS;
      if (direction == UP) {
        row--;
      } else if (direction == DOWN) {
        row++;
      } else if (direction == LEFT) {
        col--;
      } else {
        col++;
      }

      //bounds checking
      if (row < 0) {
        row = 0;
      } else if (row >= ROWS) {
        row = ROWS - 1;
      }
      if (col < 0) {
        col = 0;
      } else if (col >= COLS) {
        col = COLS - 1;
      }

      j++;
    }
    i++;
  }

  //place player
  playerLocRow = PLAYER_START_ROW;
  playerLocCol = PLAYER_START_COL;
  tiles[playerLocRow][playerLocCol] = 'p';
  tiles[PLAYER_START][PLAYER_START] = '.'; //map default constructor made (1,1) = p but we spawn player elsewhere
  
  //place stairs 'up' and 'down'
  tiles[PLAYER_START_ROW][PLAYER_START_COL - 1] = '<';
  tiles[PLAYER_START_ROW][COLS - 2] = '>';
  
  //rocks in place, carve straight path in unlikely event stairs not reachable
  i = PLAYER_START_COL + 1;
  while (tiles[PLAYER_START_ROW][i] != '>') {
    tiles[PLAYER_START_ROW][i] = '.';
    i++;
  }
}

void Dungeon::spawnMonsters() {
  //add rocks around down stairs so user can only exit once all monsters dead
  tiles[PLAYER_START_ROW][COLS - 3] = '#';
  tiles[PLAYER_START_ROW - 1][COLS - 3] = '#';
  tiles[PLAYER_START_ROW - 1][COLS - 2] = '#';
  tiles[PLAYER_START_ROW + 1][COLS - 3] = '#';
  tiles[PLAYER_START_ROW + 1][COLS - 2] = '#';

  int count = 0;
  if (level == 1) {
    while (count < ONE_MONSTERS) {
      spawnWeakMonster();
      count++;
    }
  } else if (level == 2) {
    while (count < TWO_MONSTERS) {
      spawnWeakMonster();
      count++;
    }
    spawnMedMonster();
    spawnMedMonster();
  } else if (level == 3) {
    while (count < THREE_MONSTERS) {
      spawnMedMonster();
      count++;
    }
  } else if (level == 4) {
    while (count < FOUR_MONSTERS) {
      spawnMedMonster();
      count++;
    }
    spawnWeakMonster();
    spawnWeakMonster();
    spawnHighMonster();
  } else if (level == 5) {
    while (count < FIVE_MONSTERS) {
      spawnMedMonster();
      count++;
    }
    spawnHighMonster();
    spawnHighMonster();
    spawnHighMonster();
  } else {
    while (count < SIX_MONSTERS) {
      spawnHighMonster();
      count++;
    }
    spawnMedMonster();
    spawnMedMonster();
  }

  spawnBoss();
}

void Dungeon::spawnWeakMonster() {
  int monsterNum = WEAK_MONS_MIN + (rand() % NUM_WEAK_MONS);
  Monster* theMonster = new Monster(static_cast<Monster::monsters>(monsterNum));

  srand(time(NULL));
  int row = rand() % ROWS;
  int col = rand() % COLS;
  while (tiles[row][col] != '.') {
    row = rand() % ROWS;
    col = rand() % COLS;
  }

  theMonster->row = row;
  theMonster->col = col;
  tiles[row][col] = theMonster->getName();

  monsters.push_back(theMonster);
}

void Dungeon::spawnMedMonster() {
  int monsterNum = MED_MONS_MIN + (rand() % NUM_MED_MONS);
  Monster* theMonster = new Monster(static_cast<Monster::monsters>(monsterNum));

  srand(time(NULL));
  int row = rand() % ROWS;
  int col = rand() % COLS;
  while (tiles[row][col] != '.') {
    row = rand() % ROWS;
    col = rand() % COLS;
  }

  theMonster->row = row;
  theMonster->col = col;
  tiles[row][col] = theMonster->getName();

  monsters.push_back(theMonster);
}

void Dungeon::spawnHighMonster() {
  int monsterNum = HIGH_MONS_MIN + (rand() % NUM_HIGH_MONS);
  Monster* theMonster = new Monster(static_cast<Monster::monsters>(monsterNum));

  srand(time(NULL));
  int row = rand() % ROWS;
  int col = rand() % COLS;
  while (tiles[row][col] != '.') {
    row = rand() % ROWS;
    col = rand() % COLS;
  }

  theMonster->row = row;
  theMonster->col = col;
  tiles[row][col] = theMonster->getName();

  monsters.push_back(theMonster);
}

void Dungeon::spawnBoss() {
  Monster* theMonster = new Monster(static_cast<Monster::monsters>(level 
    + BOSS_MIN - 1));

  srand(time(NULL));
  int row = rand() % ROWS;
  int col = rand() % COLS;
  while (tiles[row][col] != '.') {
    row = rand() % ROWS;
    col = rand() % COLS;
  }

  theMonster->row = row;
  theMonster->col = col;
  tiles[row][col] = theMonster->getName();

  monsters.push_back(theMonster);
}