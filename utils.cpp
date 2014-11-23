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
  cout << setw(11) << left << thePlayer->getName() << "STR:" << setw(7) 
    << thePlayer->getStr() << "WIS:" << setw(7) << thePlayer->getWisd() 
    << "CON:" << setw(7) << thePlayer->getCons() << "LEV:" << setw(7) 
    << thePlayer->getLevel() << "MANA:" << setw(7) << thePlayer->getMana() 
    << endl << setw(11) << thePlayer->getGender() << "INT:" << setw(7) 
    << thePlayer->getIntel() << "DEX:" << setw(7) << thePlayer->getDext() 
    << "CHA:" << setw(7) << thePlayer->getChar() << "EXP:" << setw(7) 
    << thePlayer->getEXP() << "GOLD:" << setw(7) << thePlayer->getGold() << endl;

  theMap->drawMap();
}