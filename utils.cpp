/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
utils.h - implementation for utils.h
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include "utils.h"


using namespace std;

Player* MakePlayer() {
  //Function to create a player with random attributes
  Player* result;

  //NEED TO WRITE THIS AS A MENU SO THEY CAN RE-ROLL STATS

  result = new Player();
  return result;
}

void DrawGame(Map* theMap, Player* thePlayer) {
  //draw status bar using player data
  cout << setw(11) << left << thePlayer->getName() << "STR:" << setw(7) 
    << thePlayer->getStr() << "HP:" << thePlayer->getHealth()
    << " /" << setw(4) << thePlayer->getMaxHealth()
    << "CON:" << setw(7) << thePlayer->getCons() << "LEV:" << setw(7) 
    << thePlayer->getLevel() << "MANA:" << setw(7) << thePlayer->getMana() 
    << endl << "HPots:" << setw(5) << thePlayer->getHealthPots() << "INT:" 
    << setw(7) << thePlayer->getIntel() << "DEX:" << setw(7) 
    << thePlayer->getDext() 
    << "CHA:" << setw(7) << thePlayer->getChar() << "EXP:" << setw(7) 
    << thePlayer->getEXP() << "GOLD:" << setw(7) << thePlayer->getGold() << endl;

  theMap->drawMap();
}

void transferItemFromStore(int itemNum, Store* theStore, Player* thePlayer) {
  vector<Item> currItemList = theStore->getItems();
  int storeInventorySize = currItemList.size();

  if (itemNum >= storeInventorySize) { 
    return;
  }

  int currGold = thePlayer->getGold();
  int price = theStore->getPrices().at(itemNum);
  int inventorySize = thePlayer->getItems().size();
  
  Item currItem = currItemList.at(itemNum);
  

  if (currGold < price) {
    return;
  } else if (inventorySize > 9) {
    return;
  } else {
    thePlayer->changeGold(-1*price);
    thePlayer->addItem(currItem);

    //Removes the item from the store
    unsigned int i;
    vector<Item> newItemList;
    vector<int> currPriceList = theStore->getPrices();
    vector<int> newPriceList;
    for (i = 0; i < currItemList.size(); i++) {
      if (i != itemNum) {
        newItemList.push_back(currItemList.at(i));
        newPriceList.push_back(currPriceList.at(i));
      }
    }
    theStore->setItems(newItemList);
    theStore->setPrices(newPriceList);

  }

}

string toString(int number) {
  ostringstream stream;
  stream << number;
  return stream.str();
}