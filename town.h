/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
town.h - specific instance of a map, contains thed default shops that the player
  can access; this is what the player returns to throughout the game
 */

#ifndef TOWN_H
#define TOWN_H


#include <vector>
#include "player.h"
#include "map.h"
#include "store.h"

#define BUY_MENU_START_ROW 1
#define BUY_MENU_START_COL 33
#define BUY_MENU_END_ROW 10
#define BUY_MENU_END_COL 64

using namespace std;

class Town: public Map {
  public:
    //make a basic town instance with given stores
    //changes tiles to represent the stores
    //thePlayer is the user's character who is displayed in the town
    //NOTE: 'door' field in stores should be unique - no other store in vector
    //  should have the same 'door' char (if you want good performance)
    Town(vector<Store*> *stores, Player* thePlayer);
    //while Player is in Town, advances game based on user input char- wasd etc.
    //returns 1 if user entered 'q' at valid time to end program
    bool performTownAction(char input);
    
  private:
    vector<Store*> *stores;
    //changes tiles to represent the Town having this Store; does not check
    //if store overlaps with other stores or has valid values. does NOT store
    //the store in the *stores vector (private below)
    void addStore(Store* aStore);
    //given w a s d, performs an action in the corresponding direction - if the
    //space is empty, causes movement; if the space is a store entrance, enter
    //the store.
    //NOTE: does nothing if not w a s d input
    //*choose to put this in Town, NOT Map since movement in a Town is different
    //from movement in a dungeon, for example (store interaction)
    void performActionInDirection(char direction);
    //goes through stores and checks if there is a store with matching door
    //returns pointer to this store if it exists, NULL pointer if not
    Store* getStoreFromDoor(char door);
    //enters an inner while loop to allow user to buy from store
    void enterBuyMenu(Store theStore);
    //changes chars in map tiles to show buy menu 'overlay'
    //usually only called once per entering store's buy menu
    void updateTilesForBuyMenu(Store theStore);
    Player* thePlayer;
};


#endif