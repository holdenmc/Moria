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
#include "map.h"
#include "town.h"
#include "store.h"
#include "item.h"


using namespace std;

int main() {
  Player* thePlayer = MakePlayer();
  vector<Store*>* stores = MakeStores();

  Town* townMap = new Town(stores, thePlayer);
  
  bool done = false; //true when we want to exit game loop
  char input;

  while (!done) {
    DrawGame(townMap, thePlayer);

    cin >> input;

    done = townMap->performTownAction(input);
  }

  delete

  return 0;
}