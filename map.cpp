/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
map.cpp - implementation for map.h
 */

#include <iostream>
#include "map.h"
#include "player.h"

using namespace std;

Map::Map () {
  thePlayer = new Player(); //defaults to default player 'john snow'

  int i, j;
  i = j = 0;

  //fill everything with periods (empty space)
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      tiles[i][j] = '.';
    }
  }

  //place boundaries for map - '#' character
  for (i = 0; i < COLS; i++) {
    tiles[0][i] = '#';
    tiles[ROWS - 1][i] = '#';
  }
  for (i = 0; i < ROWS; i++) {
    tiles[i][0] = '#';
    tiles[i][COLS - 1] = '#';
  }

  playerLocRow = playerLocCol = 1; //default player location row 1 col 1
  tiles[playerLocRow][playerLocCol] = 'p';
}

void Map::drawMap() {
  int i, j;
  i = j = 0;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      cout << tiles[i][j];
    }
    cout << endl;
  }
}