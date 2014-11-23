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
#include "map.h"
#include "store.h"

using namespace std;

class Town: public Map {
  public:
    //make a basic town instance with given stores - changes tiles to represent
    //the stores
    Town(vector<Store*> *stores);
    //changes tiles to represent the Town having this Store; does not check
    //if store overlaps with other stores or has valid values. does NOT store
    //the store in the *stores vector (private below)
    void addStore(Store* aStore);

  private:
    vector<Store*> *stores;
};


#endif