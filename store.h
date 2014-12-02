/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
store.h - contains information for a store that exists in the town
 */

#ifndef STORE_H
#define STORE_H


#include <vector>
#include <string>
#include "item.h"

#define STORE_SIZE 5 //basic store dimension - don't have to use this


using namespace std;

class Store {
  public:
    //makes a store with given dimensions and upper left corner at (row, col)
    //and entrance at (rowEnt, colEnt) RELATIVE TO THE UPPER LEFT CORNER
    Store(int row, int col, int width, int height, int rowEnt, int colEnt, 
        char door, vector<Item> items, vector<int> prices);
    int getRow();
    int getCol();
    int getWidth();
    int getHeight();
    int getRowEnt();
    int getColEnt();
    char getDoor();
    vector<Item> getItems();
    vector<int> getPrices();


  private:
    int row, col, width, height, rowEnt, colEnt;
    //char to represent the entrance when store is drawn
    char door;
    vector<Item> items;
    vector<int> prices;
};


#endif