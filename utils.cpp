/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
utils.h - implementation for utils.h
 */

#include <iomanip>
#include <iostream>
#include "player.h"
#include "town.h"

using namespace std;

void MakePlayer(Player* thePlayer) {

}

void DrawGame(Town* theMap, Player* thePlayer) {
  //draw status bar using player data
  cout << setw(11) << left << "name" << "STR:" << setw(7) << 18 << "WIS:" << setw(7) 
    << 12 << "CON:" << setw(7) << 12 << "LEV:" << setw(7) << 1 << "MANA:" 
    << setw(7) << 0 << endl << setw(11) << "male" << "INT:" << setw(7) << 11 
    << "DEX:" << setw(7) << 18 << "CHA:" << setw(7) << 9 << "EXP:" << setw(7) 
    << 0 << "GOLD:" << setw(7) << 295 << endl;

  theMap->drawMap();
}