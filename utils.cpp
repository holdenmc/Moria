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
#include <vector>
#include "utils.h"
#include "store.h"
#include "item.h"


using namespace std;

Player* MakePlayer() {
  //Function to create a player with random attributes
  Player* result;
  char input, gender;
  string name, age;
  int str, intel, dext, cons, charisma, height, weight;
  bool done = false;

  //Requests Name, gender and age first
  cout << "Name : ";
  getline(cin, name);
  cout << "Gender (type m or f): "; 
  cin >> gender;
  while (gender != 'm' && gender != 'f') {
    cout << "Try again. m for male, f for female." << endl;
    cin >> gender;
  }

  cout << "Age: ";
  cin >> age;
  while (atoi(age.c_str()) < AGE_MIN || atoi(age.c_str()) > AGE_MAX) {
    cout << "Try again. Valid ages are between 1 and 99: ";
    cin >> age;
  }

  while (!done) {
    srand(time(NULL));
    // Randomly generates stats
    if (gender == 'm') {
      str = rand() % STAT_5 + STAT_4;
      intel = rand() % STAT_5 + STAT_3;
      dext = rand() % STAT_3 + STAT_3;
      cons = rand() % STAT_3 + STAT_7;
      charisma = rand() % STAT_5 + STAT_3;
      height = rand() % HEIGHT_RANGE + M_HEIGHT_BASE;
      weight = rand() % M_WEIG_RANGE + M_WEIG_BASE;
    } else {
      str = rand() % STAT_5 + STAT_3;
      intel = rand() % STAT_5 + STAT_3;
      dext = rand() % STAT_4 + STAT_5;
      cons = rand() % STAT_3 + STAT_4;
      charisma = rand() % STAT_5 + STAT_4;
      height = rand() % HEIGHT_RANGE + F_HEIGHT_BASE;
      weight = rand() % F_WEIG_RANGE + F_WEIG_BASE;
    }

    cout <<endl << setw(CHAR_11) << left << name.substr(0, MAX_PLAYER_NAME) 
    << "STR:" << setw(CHAR_7) << str 
    << "CON:" << setw(CHAR_7) << cons 
    << "INT:" << setw(CHAR_7) << intel 
    << "DEX:" << setw(CHAR_7) << dext 
    << "CHA:" << setw(CHAR_7) << charisma << endl 
    << setw(CHAR_18) << right << "Height:" << left << setw(CHAR_4) << height 
    << "Weight:" << setw(CHAR_7) << weight << endl;

    cout << endl << "Hit r to reroll. Hit d to finish" << endl;

    cin >> input;
    while (input != 'd' && input != 'r') {
      cout << "Try again. r to re-roll, d to finish creation" << endl;
      cin >> input;
    }

    //Handles inputs
    switch(input) {
      case 'd': done = true;
                break;
      
      case 'r': break;
    }

  }

  result = new Player(str, intel, dext, cons, charisma, atoi(age.c_str()), 
                  height, weight, name.substr(0, MAX_PLAYER_NAME), gender);
  return result;
}

void DrawGame(Map* theMap, Player* thePlayer) {
  //draw status bar using player data
  cout << setw(CHAR_11) << left << thePlayer->getName()
    << "STR:" << setw(CHAR_7) << thePlayer->getStr() 
    << "HP:" << thePlayer->getHealth() << " /" << setw(CHAR_4) << thePlayer->getMaxHealth()
    << "CON:" << setw(CHAR_7) << thePlayer->getCons() 
    << "LEV:" << setw(CHAR_7) << thePlayer->getLevel() 
    << "MANA:" << setw(CHAR_7) << thePlayer->getMana() << endl 
    << "HPots:" << setw(CHAR_5) << thePlayer->getHealthPots() 
    << "INT:" << setw(CHAR_7) << thePlayer->getIntel() 
    << "DEX:" << setw(CHAR_7) << thePlayer->getDext() 
    << "CHA:" << setw(CHAR_7) << thePlayer->getChar() 
    << "EXP:" << setw(CHAR_7) << thePlayer->getEXP() 
    << "GOLD:" << setw(CHAR_7) << thePlayer->getGold() << endl;

  theMap->drawMap();
}

vector<Store*>* MakeStores() {
  vector<Item> generalItems;
  vector<Item> armoryItems;
  vector<Item> smithItems;
  vector<int> generalPrices;
  vector<int> armoryPrices;
  vector<int> smithPrices;

  //item constructor form: int i_boost, int i_indicator, int i_type
  Item hPot = Item("HP Pot", 0, 0, 0);
  generalItems.push_back(hPot);
  generalPrices.push_back(POT_PRICE);
  
  Item body1 = Item("Vest", SM_BOOST, CONS, BODY);
  Item body2 = Item("Chn Mail", MED_BOOST, CONS, BODY);
  Item body3 = Item("Plt Mail", HIGH_BOOST, CONS, BODY);
  armoryItems.push_back(body1);
  armoryPrices.push_back(VEST_PRICE);
  armoryItems.push_back(body2);
  armoryPrices.push_back(CHNMAIL_PRICE);
  armoryItems.push_back(body3);
  armoryPrices.push_back(PRICE_VHI);

  Item head1 = Item("Bandana", SM_BOOST, CONS, HELMET);
  Item head2 = Item("Skullcap", MED_BOOST, CONS, HELMET);
  Item head3 = Item("Grt Helm", MED_BOOST, STR, HELMET);
  armoryItems.push_back(head1);
  armoryPrices.push_back(PRICE_LOW);
  armoryItems.push_back(head2);
  armoryPrices.push_back(PRICE_MED);
  armoryItems.push_back(head3);
  armoryPrices.push_back(PRICE_HIGH);

  Item legs1 = Item("Trousers", SM_BOOST, CONS, LEGS);
  Item legs2 = Item("Jeggings", MED_BOOST, CHARIS, LEGS);
  Item legs3 = Item("Plt Legs", MED_BOOST, CONS, LEGS);
  armoryItems.push_back(legs1);
  armoryPrices.push_back(PRICE_LOW);
  armoryItems.push_back(legs2);
  armoryPrices.push_back(PRICE_MED);
  armoryItems.push_back(legs3);
  armoryPrices.push_back(PRICE_HIGH);

  Item weapon1 = Item("Dagger", SM_BOOST, STR, WEAPON);
  Item weapon2 = Item("Rapier", MED_BOOST, STR, WEAPON);
  Item weapon3 = Item("LngSword", MEDH_BOOST, STR, WEAPON);
  Item weapon4 = Item("BrdSword", HIGH_BOOST, STR, WEAPON);
  Item weapon5 = Item("LaserGun", VHI_BOOST, STR, WEAPON);
  smithItems.push_back(weapon1);
  smithPrices.push_back(PRICE_LOW);
  smithItems.push_back(weapon2);
  smithPrices.push_back(PRICE_MED);
  smithItems.push_back(weapon3);
  smithPrices.push_back(PRICE_HIGH);
  smithItems.push_back(weapon4);
  smithPrices.push_back(PRICE_VHI);
  smithItems.push_back(weapon5);
  smithPrices.push_back(PRICE_VVHI);

  Item shield1 = Item("CrdBoard", SM_BOOST, DEXT, SHIELD);
  Item shield2 = Item("RndShld", MED_BOOST, DEXT, SHIELD);
  Item shield3 = Item("KiteShld", MEDH_BOOST, DEXT, SHIELD);
  Item shield4 = Item("2ndSword", MED_BOOST, STR, SHIELD);
  Item shield5 = Item("TowrShld", VHI_BOOST, DEXT, SHIELD);
  smithItems.push_back(shield1);
  smithPrices.push_back(PRICE_LOW);
  smithItems.push_back(shield2);
  smithPrices.push_back(PRICE_MED);
  smithItems.push_back(shield3);
  smithPrices.push_back(PRICE_HIGH);
  smithItems.push_back(shield4);
  smithPrices.push_back(PRICE_VHI);
  smithItems.push_back(shield5);
  smithPrices.push_back(PRICE_VVHI);

  Store* general = new Store(STORE_SIZE, STORE_SIZE, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'g', generalItems, generalPrices);
  Store* armory = new Store(STORE_SIZE, STORE_SIZE*STORE_SEP_1, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'a', armoryItems, armoryPrices);
  Store* smith = new Store(STORE_SIZE, STORE_SIZE*STORE_SEP_2, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 's', smithItems, smithPrices);
  
  /*Store* temple = new Store(STORE_SIZE+7, STORE_SIZE, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 't', items, prices);
  Store* alchemy = new Store(STORE_SIZE+7, STORE_SIZE*3, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'c', items, prices);
  Store* magic = new Store(STORE_SIZE+7, STORE_SIZE*5, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'm', items, prices);*/

  vector<Store*>* stores = new vector<Store*>;
  stores->push_back(general);
  stores->push_back(armory);
  stores->push_back(smith);

  /*stores.push_back(temple);
  stores.push_back(alchemy);
  stores.push_back(magic);*/

  return stores;
}

void transferItemFromStore(int itemNum, Store* theStore, Player* thePlayer) {
  vector<Item> currItemList = theStore->getItems();
  int storeInventorySize = currItemList.size();

  //Checks if itemNum is even valid in the first place
  if (itemNum >= storeInventorySize) { 
    return;
  }

  int currGold = thePlayer->getGold();
  int price = theStore->getPrices().at(itemNum);
  int inventorySize = thePlayer->getItems().size();
  
  Item currItem = currItemList.at(itemNum);
  int charisma = thePlayer->getChar();

  //First check is if you have enough gold
  if (currGold < price) {
    return;
  } else if (inventorySize > INVENT_SIZE) {//Checks if inventory is full
    return;
  } else {
    //Handles charisma-based price reduction
    int priceReduce = 0;
    if (charisma > CHARIS_CHANGE) {
      priceReduce = PRICE_REDUC * (charisma - CHARIS_FACTOR);
    }
    thePlayer->changeGold(-1*(price - priceReduce));
    //Handles the fact that the general store just sells HPots
    if (theStore->getDoor() == 'g') {
      thePlayer->setHealthPot(thePlayer->getHealthPots() + 1);
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

// Converts an integer into a string.  like .to_string in c++11
string toString(int number) {
  ostringstream stream;
  stream << number;
  return stream.str();
}

