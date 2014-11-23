/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
map.h - general 66 by 22 grid of characters to represent a game's status
 */
#ifndef MAP_H
#define MAP_H


#define ROWS 20
#define COLS 66

class Map {
  public:
    //make basic empty map
    Map();
    //draw the map
    void drawMap();

  protected:
    //lets Town, etc. access what tiles (and hence, the Map) looks like
    void setTiles(int row, int col, char val);

  private:
    char tiles[ROWS][COLS];
};


#endif