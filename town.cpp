/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
town.cpp - implementation for town.h
 */

#include <vector>
#include <iostream>
#include "town.h"
#include "store.h"

Town::Town (vector<Store*> *stores) {
  this->stores = stores;
  unsigned int i = 0;
  for (i = 0; i < stores->size(); i++) {
    addStore((*stores)[i]);
  }
}

void Town::addStore(Store* aStore) {
  int i, j;
  for (i = aStore->getRow(); i < aStore->getRow() + aStore->getHeight(); i++) {
    for (j = aStore->getCol(); j < aStore->getCol() + aStore->getWidth(); j++) {
      setTiles(i, j, '#');
    }
  }

  setTiles(aStore->getRowEnt(), aStore->getColEnt(), aStore->getIndicator());
}

