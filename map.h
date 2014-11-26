/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
map.h - general 66 by 22 grid of characters to represent the game's status,
  subclasses like Town or Dungeon expected to implement more specific behaviors
 */
#ifndef MAP_H
#define MAP_H


#define ROWS 20
#define COLS 66

class Map {
  public:
    //make basic empty map with default player location at row 1 col 1
    Map();
    //draw the map
    void drawMap();
    //move the player up left down or right - w a s d; does nothing for other
    //chars; player only moves to new space if it is empty - contains '.' char
    void movePlayer(char direction);

  protected:
    //change char at given row and col to given char val
    //lets Town, etc. access what tiles (and hence, the Map) looks like
    void setTiles(int row, int col, char val);

  private:
    char tiles[ROWS][COLS];
    int playerLocRow, playerLocCol; //track the one player on the map
};


#endif