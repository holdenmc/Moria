/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
store.cpp - implementation for store.h
 */

#include "store.h"

Store::Store(int row, int col, int width, int height, int rowEnt, int colEnt, 
    char indicator) {
  this->row = row;
  this->col = col;
  this->width = width;
  this->height = height;
  this->rowEnt = row + rowEnt;
  this->colEnt = col + colEnt;
  this->indicator = indicator;
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

char Store::getIndicator() {
  return indicator;
}