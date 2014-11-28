/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
town.cpp - implementation for town.h
 */

#include <vector>
#include <iostream>
#include "utils.h"
#include "player.h"
#include "town.h"
#include "store.h"

Town::Town (vector<Store*> *stores, Player* thePlayer) {
  this->stores = stores;
  unsigned int i = 0;
  for (i = 0; i < stores->size(); i++) {
    addStore((*stores)[i]);
  }

  this->thePlayer = thePlayer;
}

void Town::performActionInDirection(char direction) {
  if (direction == 'w') {
    //check for empty space...
    if (tiles[playerLocRow - 1][playerLocCol] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocRow--;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow - 1][playerLocCol] != '#') {
      Store* possStore = getStoreFromDoor(tiles[playerLocRow-1][playerLocCol]);
      if (possStore != NULL) {
        enterBuyMenu(*possStore);
      }
    }
  } else if (direction == 'a') {
    if (tiles[playerLocRow][playerLocCol - 1] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocCol--;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow][playerLocCol - 1] != '#') {
      Store* possStore = getStoreFromDoor(tiles[playerLocRow][playerLocCol-1]);
      if (possStore != NULL) {
        enterBuyMenu(*possStore);
      }
    }
  } else if (direction == 's') {
    if (tiles[playerLocRow + 1][playerLocCol] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocRow++;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow + 1][playerLocCol] != '#') {
      Store* possStore = getStoreFromDoor(tiles[playerLocRow+1][playerLocCol]);
      if (possStore != NULL) {
        enterBuyMenu(*possStore);
      }
    }
  } else if (direction == 'd') {
    if (tiles[playerLocRow][playerLocCol + 1] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocCol++;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow][playerLocCol + 1] != '#') {
      Store* possStore = getStoreFromDoor(tiles[playerLocRow][playerLocCol+1]);
      if (possStore != NULL) {
        enterBuyMenu(*possStore);
      }
    }
  }
}

bool Town::performTownAction(char input) {
  if (input == 'q') {
    return true;
  } else {
    performActionInDirection(input);
  }

  return false;
}

void Town::addStore(Store* aStore) {
  int i, j;
  for (i = aStore->getRow(); i < aStore->getRow() + aStore->getHeight(); i++) {
    for (j = aStore->getCol(); j < aStore->getCol() + aStore->getWidth(); j++) {
      tiles[i][j] = '#';
    }
  }

  tiles[aStore->getRowEnt()][aStore->getColEnt()] = aStore->getDoor();
}

Store* Town::getStoreFromDoor(char door) {
  unsigned int i;
  for (i = 0; i < stores->size(); i++) {
    if ((*stores)[i]->getDoor() == door) {
      return (*stores)[i];
    }
  }

  return NULL;
}

void Town::enterBuyMenu(Store theStore) {
  //copy original town map
  int i, j;
  char original[ROWS][COLS];
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      original[i][j] = tiles[i][j];
    }
  }

  updateTilesForBuyMenu(theStore);//make look like buy menu
  DrawGame(this, thePlayer); //draw the screen now that values have been updated

  bool done = false;
  char input;
  while (!done) {
    cin >> input;
    if (input == 'q') {
      done = true;
    }

    DrawGame(this, thePlayer);
  }

  //done with buy menu, return town map to previous state
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      tiles[i][j] = original[i][j];
    }
  }
}

void Town::updateTilesForBuyMenu(Store theStore) {
  //set boundaries - run in square row 1 row 10 col 33 col 64
  int i = BUY_MENU_START_COL;
  while (i <= BUY_MENU_END_COL) {
    tiles[BUY_MENU_START_ROW][i] = '=';
    tiles[BUY_MENU_END_ROW][i] = '=';
    i++;
  }

  i = BUY_MENU_START_ROW;
  while (i <= BUY_MENU_END_ROW) {
    tiles[i][BUY_MENU_START_COL] = '|';
    tiles[i][BUY_MENU_END_COL] = '|';
    i++;
  }
}
