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
#include <time.h>
#include <cstdlib>
#include "utils.h"


using namespace std;

Player* MakePlayer() {
  //Function to create a player with random attributes
  Player* result;
  char input;
  string name;
  char gender;
  int str, intel, dext, cons, charisma, age, height, weight;
  bool done = false;

  //NEED TO WRITE THIS AS A MENU SO THEY CAN RE-ROLL STATS
  cout << "Name : ";
  getline(cin, name);
  cout << "Gender (type m or f): "; 
  cin >> gender;
  while (gender != 'm' && gender != 'f') {
    cout << "Try again.  m for male, f for female." << endl;
    cin >> gender;
  }

  cout << "Age: ";
  cin >> age;
  while (age < 0 || age > 99) {
    cout << "Try again.  Valid ages are between 1 and 99." << endl;
    cin >> gender;
  }

  while (!done) {
    srand(time(NULL));
    if (gender == 'm') {
      str = rand() % 5 + 4;
      intel = rand() % 5 + 3;
      dext = rand() % 3 + 3;
      cons = rand() % 3 + 7;
      charisma = rand() % 5 + 3;
      height = rand() % 20 + 68;
      weight = rand() % 100 + 180;

    } else {
      str = rand() % 5 + 3;
      intel = rand() % 5 + 3;
      dext = rand() % 4 + 5;
      cons = rand() % 3 + 4;
      charisma = rand() % 5 + 4;
      height = rand() % 20 + 62;
      weight = rand() % 50 + 140;
    }

    cout <<endl << setw(11) << left << name << "STR:" << setw(7) << str <<"CON:" 
    << setw(7) << cons << "INT:" << setw(7) << intel << "DEX:" << setw(7) 
    << dext << "CHA:" << setw(7) << charisma << endl << setw(18) << right
    << "Height:" << left << setw(4) << height << "Weight:" << setw(7) << weight 
    << endl;

    cout << endl << "Hit r to reroll.  Hit d to finish" << endl;

    cin >> input;

    while (input != 'd' && input != 'r') {
      cout << "Try again.  r to re-roll, d to finish creation" << endl;
      cin >> input;
    }

    switch(input) {
      case 'd': done = true;
                break;
      
      case 'r': break;
    }

  }

  result = new Player(str, intel, dext, cons, charisma, age, height, 
                      weight, name, gender);
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
  int charisma = thePlayer->getChar();

  if (currGold < price) {
    return;
  } else if (inventorySize > 9) {
    return;
  } else {
    int priceReduce = 0;
    if (charisma > 8) {
      priceReduce = 2*(charisma - 5);
    }
    thePlayer->changeGold(-1*(price - priceReduce));
    
    if (theStore->getDoor() == 'g') {
      thePlayer->setHealthPot(1 + thePlayer->getHealthPots());
      return;
    }

    thePlayer->addItem(currItem);

    //Removes the item from the store
    unsigned int i;
    vector<Item> newItemList;
    vector<int> currPriceList = theStore->getPrices();
    vector<int> newPriceList;
    for (i = 0; i < currItemList.size(); i++) {
      if (i != (unsigned int)itemNum) {
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