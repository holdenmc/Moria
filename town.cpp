/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
town.cpp - implementation for town.h
 */

#include <vector>
#include <iostream>
#include <string>
#include "utils.h"
#include "player.h"
#include "map.h"
#include "town.h"
#include "store.h"
#include "dungeon.h"

Town::Town (vector<Store*> *stores, Player* thePlayer) {
  this->stores = stores;
  unsigned int i = 0;
  for (i = 0; i < stores->size(); i++) {
    addStore((*stores)[i]);
  }

  this->thePlayer = thePlayer;
  tiles[DUNGEON_ENT_ROW][DUNGEON_ENT_COL] = '>';
}

bool Town::performTownAction(char input) {
  switch(input) {
    case 'q': return true;

    case 'i': handleInventory();

    case 'h': thePlayer->drinkHealthPot();

    case 'w':
    case 'a':
    case 's':
    case 'd': performActionInDirection(input);
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

void Town::performActionInDirection(char direction) {
  if (direction == 'w') {
    //check for empty space...
    if (tiles[playerLocRow - 1][playerLocCol] == '.') {
      tiles[playerLocRow][playerLocCol] = '.';
      playerLocRow--;
      tiles[playerLocRow][playerLocCol] = 'p';
    } else if (tiles[playerLocRow - 1][playerLocCol] == '>') { //enter dungeon
      Dungeon* firstDungeon = new Dungeon(thePlayer);
      firstDungeon->enterDungeonLoop();
      delete(firstDungeon);
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
    } else if (tiles[playerLocRow][playerLocCol - 1] == '>') {
      Dungeon* firstDungeon = new Dungeon(thePlayer);
      firstDungeon->enterDungeonLoop();
      delete(firstDungeon);
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
    } else if (tiles[playerLocRow + 1][playerLocCol] == '>') {
      Dungeon* firstDungeon = new Dungeon(thePlayer);
      firstDungeon->enterDungeonLoop();
      delete(firstDungeon);
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
    } else if (tiles[playerLocRow][playerLocCol + 1] == '>') {
      Dungeon* firstDungeon = new Dungeon(thePlayer);
      firstDungeon->enterDungeonLoop();
      delete(firstDungeon);
    } else if (tiles[playerLocRow][playerLocCol + 1] != '#') {
      Store* possStore = getStoreFromDoor(tiles[playerLocRow][playerLocCol+1]);
      if (possStore != NULL) {
        enterBuyMenu(*possStore);
      }
    }
  }
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

  updateTilesForBuyMenu(&theStore);//make look like buy menu
  DrawGame(this, thePlayer); //draw the screen now that values have been updated

  bool done = false;
  char input;
  int inputInt = -1; //Initialize to an unused value
  while (!done) {
    cin >> input;

    //Use the q key to exit the menu
    if (input == 'q') {
      done = true;
    }
    inputInt = (int)input - 48;
    //Handles the potential buying options
    switch(inputInt) {
      case 0:
      case 1: 
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9: transferItemFromStore(inputInt, &theStore, thePlayer);
                break;
    }

    updateTilesForBuyMenu(&theStore); //Rebuild the menu with the item gone
    DrawGame(this, thePlayer);
  }

  //done with buy menu, return town map to previous state
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      tiles[i][j] = original[i][j];
    }
  }
}

void Town::updateTilesForBuyMenu(Store* theStore) {
  unsigned int i, j, itemNum;
  string currString;
  char currentChar = '0';
  vector<Item> items = theStore->getItems();
  vector<int> prices = theStore->getPrices();
  string instruct = "Enter # to buy, q to quit";

  //Clear out the entire space until it's populated later
  for(i = BUY_MENU_START_ROW; i <= BUY_MENU_END_ROW; i++) {
    for(j = BUY_MENU_START_COL; j <= BUY_MENU_END_COL; j++) {
      tiles[i][j] = ' ';
    }
  }

  //Write out instructions
  for(j = 0; j < instruct.length(); j++) {
      currentChar = instruct.at(j);
      tiles[BUY_MENU_START_ROW + 1][BUY_MENU_START_COL + 1 + j] = currentChar;
  }

  //set boundaries - run in square row 1 row 10 col 33 col 64
  i = BUY_MENU_START_COL;
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

  //Write the numbers for the items
  currentChar = '0';
  i = BUY_MENU_START_ROW + MENU_SPACING;
  while (i <= BUY_MENU_END_ROW - MENU_SPACING - 1) {
    tiles[i][BUY_MENU_START_COL + 1] = currentChar;

    if (currentChar <= '0' + (COL_MAX - MENU_SPACING + 1)) {
      tiles[i][BUY_MENU_START_COL + 2 + MENU_SPACING + PRINTED_STRING_LEN + 
        PRICE_DIGITS] = currentChar + 5;
    }
    currentChar++;
    i++;
  }

  //Iterates the first column of items
  for (itemNum = 0; itemNum < COL_MAX && itemNum < items.size(); itemNum++) {
    i = BUY_MENU_START_COL + MENU_SPACING + 1;
    j = 0;

    currString = items.at(itemNum).getName();
    //Prints out the name of the item (first 8 chars)
    for(j = 0; j < currString.length(); j++) {
      currentChar = currString.at(j);
      tiles[BUY_MENU_START_ROW + itemNum + MENU_SPACING][i+j] = currentChar;
    }
    
    i += PRINTED_STRING_LEN;
    currString = toString(prices.at(itemNum));
    for(j = 0; j < currString.length() && j < PRICE_DIGITS; j++) {
      currentChar = currString.at(j);
      tiles[BUY_MENU_START_ROW + itemNum + MENU_SPACING][i+j] = currentChar;
    }

  }
  int firstColumnSpace = MENU_SPACING + PRINTED_STRING_LEN + PRICE_DIGITS;
  if (items.size() > COL_MAX)
  for (itemNum = COL_MAX; itemNum < items.size(); itemNum++) {
    i = BUY_MENU_START_COL + MENU_SPACING + firstColumnSpace + 2;
    j = 0;

    currString = items.at(itemNum).getName();
    //Prints out the name of the item (first 8 chars)
    for(j = 0; j < currString.length() && j < 2*COL_MAX; j++) {
      currentChar = currString.at(j);
      tiles[BUY_MENU_START_ROW + itemNum - COL_MAX + MENU_SPACING][i+j] 
        = currentChar;
    }
    
    i += PRINTED_STRING_LEN;
    currString = toString(prices.at(itemNum));
    for(j = 0; j < currString.length() && j < PRICE_DIGITS; j++) {
      currentChar = currString.at(j);
      tiles[BUY_MENU_START_ROW + itemNum - COL_MAX + MENU_SPACING][i+j] 
        = currentChar;
    }
  }
}

void Town::drawInventory() {
  unsigned int i, j, itemNum;
  string currString;
  char currentChar = '0';
  vector<Item> items = thePlayer->getItems();
  string instruct = "Enter # to (un)equip";

  //Clear out the entire space until it's populated later
  for(i = BUY_MENU_START_ROW; i <= BUY_MENU_END_ROW; i++) {
    for(j = BUY_MENU_START_COL; j <= BUY_MENU_END_COL; j++) {
      tiles[i][j] = ' ';
    }
  }

  //Write out instructions
  for(j = 0; j < instruct.length(); j++) {
      currentChar = instruct.at(j);
      tiles[BUY_MENU_START_ROW + 1][BUY_MENU_START_COL + 1 + j] = currentChar;
  }

  //set boundaries - run in square row 1 row 10 col 33 col 64
  i = BUY_MENU_START_COL;
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

  //Write the numbers for the items
  currentChar = '0';
  i = BUY_MENU_START_ROW + MENU_SPACING;
  while (i <= BUY_MENU_END_ROW - MENU_SPACING - 1) {
    tiles[i][BUY_MENU_START_COL + 1] = currentChar;

    if (currentChar <= '0' + (COL_MAX - MENU_SPACING + 1)) {
      tiles[i][BUY_MENU_START_COL + 2 + MENU_SPACING + PRINTED_STRING_LEN + 
        PRICE_DIGITS] = currentChar + 5;
    }
    currentChar++;
    i++;
  }

  //Iterates the first column of items
  for (itemNum = 0; itemNum < COL_MAX && itemNum < items.size(); itemNum++) {
    i = BUY_MENU_START_COL + MENU_SPACING + 1;
    j = 0;

    currString = items.at(itemNum).getName();
    //Prints out the name of the item (first 8 chars)
    for(j = 0; j < currString.length(); j++) {
      currentChar = currString.at(j);
      tiles[BUY_MENU_START_ROW + itemNum + MENU_SPACING][i+j] = currentChar;
    }
    
    i += PRINTED_STRING_LEN;
    if (items.at(itemNum).getEquip()) {
      currentChar = 'E';
      tiles[BUY_MENU_START_ROW + itemNum + MENU_SPACING][i] = currentChar;
    }

  }
  int firstColumnSpace = MENU_SPACING + PRINTED_STRING_LEN + PRICE_DIGITS;
  if (items.size() > COL_MAX)
  for (itemNum = COL_MAX; itemNum < items.size(); itemNum++) {
    i = BUY_MENU_START_COL + MENU_SPACING + firstColumnSpace + 2;
    j = 0;

    currString = items.at(itemNum).getName();
    //Prints out the name of the item (first 8 chars)
    for(j = 0; j < currString.length() && j < 2*COL_MAX; j++) {
      currentChar = currString.at(j);
      tiles[BUY_MENU_START_ROW + itemNum - COL_MAX + MENU_SPACING][i+j] 
        = currentChar;
    }
    
    i += PRINTED_STRING_LEN;
    if (items.at(itemNum).getEquip()) {
      currentChar = 'E';
      tiles[BUY_MENU_START_ROW + itemNum - COL_MAX + MENU_SPACING][i] = currentChar;
    }
  }


}

void Town::handleInventory() {
  int i, j;
  char original[ROWS][COLS];
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      original[i][j] = tiles[i][j];
    }
  }

  drawInventory(); //Updates the tiles to be the inventory
  DrawGame(this, thePlayer); //draw the screen now that values have been updated

  bool done = false;
  char input;
  int inputInt = -1; //Initialize to an unused value
  vector<Item> currItemList = thePlayer->getItems();
  while (!done) {
    cin >> input;

    //Use the q key to exit the menu
    if (input == 'q') {
      done = true;
    }
    inputInt = (int)input - 48;
    //Handles the potential equipping options
    
    Item currItem;
    Item chosenItem;
    switch(inputInt) {
      case 0:
      case 1: 
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9: chosenItem = currItemList.at(inputInt);
              if (inputInt < (int)thePlayer->getItems().size()) {
                currItemList.at(inputInt).setEquip(!chosenItem.getEquip());
                for (i = 0; i < (int)currItemList.size(); i++) {
                  currItem = currItemList.at(i);
                  if (chosenItem.getType() == currItem.getType() 
                    && currItem.getEquip()
                    && chosenItem.getName().compare(currItem.getName()) != 0) {
                    
                    currItemList.at(i).setEquip(false);
                  }
                }
                thePlayer->setItems(currItemList);
              }
              break;
    }

    drawInventory(); //Draw again now that equip is changed
    thePlayer->refreshStats();
    DrawGame(this, thePlayer);

  }

  //done with inventory menu, return town map to previous state
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      tiles[i][j] = original[i][j];
    }
  }


}






