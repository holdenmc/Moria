/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
utils.h - delcarations for general utility functions to assist in basic game
  operation
 */
#ifndef UTILS_H
#define UTILS_H

#define AGE_MIN         1
#define AGE_MAX         99
#define MAX_PLAYER_NAME 11
#define STORE_SEP_1     3
#define STORE_SEP_2     5
#define STAT_3          3
#define STAT_4          4
#define STAT_5          5
#define STAT_7          7
#define M_HEIGHT_BASE   68
#define F_HEIGHT_BASE   62
#define HEIGHT_RANGE    20
#define M_WEIG_BASE     180
#define F_WEIG_BASE     140
#define M_WEIG_RANGE    100
#define F_WEIG_RANGE    50
#define CHAR_4          4 //for printing things properly; char width constants
#define CHAR_5          5
#define CHAR_7          7
#define CHAR_11         11
#define CHAR_18         18
#define INVENT_SIZE     9
#define CHARIS_CHANGE   8
#define PRICE_REDUC     2
#define CHARIS_FACTOR   5

#include <vector>
#include <string>
#include "player.h"
#include "town.h"
#include "store.h"


//Made methods capital letter first if they setup game/draw it
//walks user through selection screen to make their player with statistics
Player* MakePlayer();

//draws the screen given map and status bar
void DrawGame(Map* theMap, Player* thePlayer);

//goes through annoying details of making the stores vector
vector<Store*>* MakeStores();



//Transfers an item from the store to the player
void transferItemFromStore(int itemNum, Store* theStore, Player* thePlayer);

//since g++ likes to be annoying with to_string -_-
string toString(int number);

#endif