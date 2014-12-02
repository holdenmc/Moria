/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
dungeon.cpp - implementation for dungeon.cpp
 */

#include <time.h>
#include <cstdlib>
#include <iostream>
#include "map.h"
#include "dungeon.h"
#include "player.h"
#include "utils.h"

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
  if (input == 'q') { //TODO: change this
    return true;
  } else {
    performActionInDirection(input);
  }

  return false;
}

void Dungeon::performActionInDirection(char direction) {
  if (direction == 'w') {
    //check for empty space...
    if (tiles[playerLocRow - 1][playerLocCol] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocRow--;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow - 1][playerLocCol] == '>') { //next level
      Dungeon* nextLevel = next();
      nextLevel->enterDungeonLoop();
    }
  } else if (direction == 'a') {
    if (tiles[playerLocRow][playerLocCol - 1] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocCol--;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow][playerLocCol - 1] == '>') {
      Dungeon* nextLevel = next();
      nextLevel->enterDungeonLoop();
    }
  } else if (direction == 's') {
    if (tiles[playerLocRow + 1][playerLocCol] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocRow++;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow + 1][playerLocCol] == '>') {
      Dungeon* nextLevel = next();
      nextLevel->enterDungeonLoop();
    }
  } else if (direction == 'd') {
    if (tiles[playerLocRow][playerLocCol + 1] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocCol++;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow][playerLocCol + 1] == '>') {
      Dungeon* nextLevel = next();
      nextLevel->enterDungeonLoop();
    }
  }
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
  //place stairs 'up' and 'down'
  tiles[PLAYER_START_ROW][PLAYER_START_COL - 1] = '<';
  tiles[PLAYER_START_ROW][COLS - 2] = '>';
  //rocks in place, carve straight path to make sure down stairs are reachable
  i = PLAYER_START_COL + 1;
  while (tiles[PLAYER_START_ROW][i] != '>') {
    tiles[PLAYER_START_ROW][i] = '.';
    i++;
  }
}

void Dungeon::spawnMonsters() {
  //TODO: this!
}