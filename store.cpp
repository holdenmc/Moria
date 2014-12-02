/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
store.cpp - implementation for store.h
 */

#include "store.h"

Store::Store(int row, int col, int width, int height, int rowEnt, int colEnt, 
    char door, vector<Item> items, vector<int> prices) {
  this->row = row;
  this->col = col;
  this->width = width;
  this->height = height;
  this->rowEnt = row + rowEnt;
  this->colEnt = col + colEnt;
  this->door = door;
  this->items = items;
  this->prices = prices;
}

int Store::getRow() {
  return row;
}

int Store::getCol() {
  return col;
}

int Store::getWidth() {
  return width;
}

int Store::getHeight() {
  return height;
}

int Store::getRowEnt() {
  return rowEnt;
}

int Store::getColEnt() {
  return colEnt;
}

char Store::getDoor() {
  return door;
}

vector<Item> Store::getItems() {
  return items;
}

vector<int> Store::getPrices() {
  return prices;
}

void Store::setItems(vector<Item> newItemList) {
  items = newItemList;
  return;
}