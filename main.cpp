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

  //make default stores for town... TODO move this into function in utils?
  //...or maybe into default Town constructor?
  vector<Item> generalItems;
  vector<Item> armoryItems;
  vector<Item> smithItems;
  vector<int> generalPrices;
  vector<int> armoryPrices;
  vector<int> smithPrices;

  /*indicators
  1 - str
  2 - intel
  3 - dext 
  4 - cons 
  5 -charisma

  types
  1 - weapon
  2 - helmet
  3 - body
  4 - legs
  5 - shield
  string i_name, int i_boost, int i_indicator, int i_type
  */


  Item hPot = Item("HP Pot", 0, 0, 0);
  generalItems.push_back(hPot);
  generalPrices.push_back(100);
  
  Item body1 = Item("Vest", 1, 4, 3);
  Item body2 = Item("Chn Mail", 2, 4, 3);
  Item body3 = Item("Plt Mail", 4, 4, 3);
  armoryItems.push_back(body1);
  armoryPrices.push_back(500);
  armoryItems.push_back(body2);
  armoryPrices.push_back(1200);
  armoryItems.push_back(body3);
  armoryPrices.push_back(2500);

  Item head1 = Item("Bandana", 1, 4, 2);
  Item head2 = Item("Skullcap", 2, 4, 2);
  Item head3 = Item("Grt Helm", 2, 1, 2);
  armoryItems.push_back(head1);
  armoryPrices.push_back(250);
  armoryItems.push_back(head2);
  armoryPrices.push_back(700);
  armoryItems.push_back(head3);
  armoryPrices.push_back(1500);

  Item legs1 = Item("Trousers", 1, 4, 4);
  Item legs2 = Item("Jeggings", 2, 5, 4);
  Item legs3 = Item("Plt Legs", 2, 4, 4);
  armoryItems.push_back(legs1);
  armoryPrices.push_back(250);
  armoryItems.push_back(legs2);
  armoryPrices.push_back(700);
  armoryItems.push_back(legs3);
  armoryPrices.push_back(1500);

  Item weapon1 = Item("Dagger", 1, 1, 1);
  Item weapon2 = Item("Rapier", 2, 1, 1);
  Item weapon3 = Item("LngSword", 3, 1, 1);
  Item weapon4 = Item("BrdSword", 4, 1, 1);
  Item weapon5 = Item("LaserGun", 6, 1, 1);
  smithItems.push_back(weapon1);
  smithPrices.push_back(250);
  smithItems.push_back(weapon2);
  smithPrices.push_back(700);
  smithItems.push_back(weapon3);
  smithPrices.push_back(1500);
  smithItems.push_back(weapon4);
  smithPrices.push_back(2500);
  smithItems.push_back(weapon5);
  smithPrices.push_back(5000);

  Item shield1 = Item("CrdBoard", 1, 3, 5);
  Item shield2 = Item("RndShld", 2, 3, 5);
  Item shield3 = Item("KiteShld", 3, 3, 5);
  Item shield4 = Item("2ndSword", 2, 1, 5);
  Item shield5 = Item("TowrShld", 6, 3, 5);
  smithItems.push_back(shield1);
  smithPrices.push_back(250);
  smithItems.push_back(shield2);
  smithPrices.push_back(700);
  smithItems.push_back(shield3);
  smithPrices.push_back(1500);
  smithItems.push_back(shield4);
  smithPrices.push_back(2500);
  smithItems.push_back(shield5);
  smithPrices.push_back(5000);

  Store* general = new Store(STORE_SIZE, STORE_SIZE, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'g', generalItems, generalPrices);
  Store* armory = new Store(STORE_SIZE, STORE_SIZE*3, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'a', armoryItems, armoryPrices);
  Store* smith = new Store(STORE_SIZE, STORE_SIZE*5, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 's', smithItems, smithPrices);
  
  /*Store* temple = new Store(STORE_SIZE+7, STORE_SIZE, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 't', items, prices);
  Store* alchemy = new Store(STORE_SIZE+7, STORE_SIZE*3, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'c', items, prices);
  Store* magic = new Store(STORE_SIZE+7, STORE_SIZE*5, STORE_SIZE, STORE_SIZE,
    STORE_SIZE - 1, STORE_SIZE - 1, 'm', items, prices);*/

  vector<Store*> stores;
  stores.push_back(general);
  stores.push_back(armory);
  stores.push_back(smith);
  
  /*stores.push_back(temple);
  stores.push_back(alchemy);
  stores.push_back(magic);*/


  Town* townMap = new Town(&stores, thePlayer);
  bool done = false; //true when we want to exit game loop
  char input;

  while (!done) {
    DrawGame(townMap, thePlayer);

    cin >> input;

    done = townMap->performTownAction(input);
  }

  return 0;
}