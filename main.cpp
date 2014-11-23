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


  //make default stores for town
  vector<Store*> stores;
  Store* general = new Store(STORE_SIZE, STORE_SIZE, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'g');
  Store* armory = new Store(STORE_SIZE, STORE_SIZE*3, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'a');
  Store* smith = new Store(STORE_SIZE, STORE_SIZE*5, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 's');
  Store* temple = new Store(STORE_SIZE+7, STORE_SIZE, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 't');
  Store* alchemy = new Store(STORE_SIZE+7, STORE_SIZE*3, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'c');
  Store* magic = new Store(STORE_SIZE+7, STORE_SIZE*5, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'm');
  stores.push_back(general);
  stores.push_back(armory);
  stores.push_back(smith);
  stores.push_back(temple);
  stores.push_back(alchemy);
  stores.push_back(magic);


  Town* townMap = new Town(&stores);
  bool done = false; //true when we want to exit game loop

  //while (!done) {
    DrawGame(townMap, thePlayer);

    int x;
    cin >> x;
  //}
}