/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
utils.h - delcarations for general utility functions to assist in basic game
  operation
 */
#ifndef UTILS_H
#define UTILS_H


#include <vector>
#include "player.h"
#include "town.h"
#include "store.h"


//walks user through selection screen to make their player with statistics
void MakePlayer(Player* thePlayer);

//draws the screen given map and status bar
void DrawGame(Town* theMap, Player* thePlayer);


#endif