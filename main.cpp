/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
main.cpp - main function to control game operation
  operation
 */

#include <vector>
#include <iostream>
#include "player.h"
#include "utils.h"
#include "town.h"
#include "store.h"

using namespace std;

int main() {
  Player* thePlayer = new Player();
  MakePlayer(thePlayer);


  //make default stores for town... TODO move this into function in utils?
  //...or maybe into default Town constructor?
  vector<string> items;
  items.push_back("item1");
  items.push_back("item2");
  items.push_back("item3");
  vector<int> prices;
  prices.push_back(100);
  prices.push_back(200);
  prices.push_back(300);
  Store* general = new Store(STORE_SIZE, STORE_SIZE, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'g', items, prices);
  Store* armory = new Store(STORE_SIZE, STORE_SIZE*3, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'a', items, prices);
  Store* smith = new Store(STORE_SIZE, STORE_SIZE*5, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 's', items, prices);
  Store* temple = new Store(STORE_SIZE+7, STORE_SIZE, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 't', items, prices);
  Store* alchemy = new Store(STORE_SIZE+7, STORE_SIZE*3, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'c', items, prices);
  Store* magic = new Store(STORE_SIZE+7, STORE_SIZE*5, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'm', items, prices);
  vector<Store*> stores;
  stores.push_back(general);
  stores.push_back(armory);
  stores.push_back(smith);
  stores.push_back(temple);
  stores.push_back(alchemy);
  stores.push_back(magic);


  Town* townMap = new Town(&stores, thePlayer);
  bool done = false; //true when we want to exit game loop
  char input;

  while (!done) {
    DrawGame(townMap, thePlayer);

    cin >> input;

    done = townMap->performTownAction(input);
  }
}