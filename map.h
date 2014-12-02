/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
map.h - general 66 by 22 grid of characters to represent the game's status,
  subclasses like Town or Dungeon expected to implement more specific behaviors
 */
#ifndef MAP_H
#define MAP_H


#include "player.h"

#define ROWS 20
#define COLS 66
#define PLAYER_START 1

class Map {
  public:
    //make basic empty map with default player location at row 1 col 1
    Map();
    //draw the map
    void drawMap();

  protected:
    char tiles[ROWS][COLS];
    //track the one player on the map
    int playerLocRow, playerLocCol; 
    //the player in the town...
    Player* thePlayer;

  private:
    
};


#endif