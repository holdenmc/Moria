/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
utils.h - implementation for utils.h
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include "utils.h"


using namespace std;

Player* MakePlayer() {
  //Function to create a player with random attributes
  Player* result;


  result = new Player();
  return result;
}

void DrawGame(Map* theMap, Player* thePlayer) {
  //draw status bar using player data
  cout << setw(11) << left << thePlayer->getName() << "STR:" << setw(7) 
    << thePlayer->getStr() << "HP:" << setw(8) << thePlayer->getHealth() 
    << "CON:" << setw(7) << thePlayer->getCons() << "LEV:" << setw(7) 
    << thePlayer->getLevel() << "MANA:" << setw(7) << thePlayer->getMana() 
    << endl << "HPots:" << setw(7) << thePlayer->getHealthPots() << "INT:" 
    << setw(7) << thePlayer->getIntel() << "DEX:" << setw(7) 
    << thePlayer->getDext() 
    << "CHA:" << setw(7) << thePlayer->getChar() << "EXP:" << setw(7) 
    << thePlayer->getEXP() << "GOLD:" << setw(7) << thePlayer->getGold() << endl;

  theMap->drawMap();
}

void transferItemFromStore(int itemNum, Store* theStore, Player* thePlayer) {
  //TODO: WRITE THIS STUFF

}

string toString(int number) {
  ostringstream stream;
  stream << number;
  return stream.str();
}