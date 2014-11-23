/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
player.h - controls all data and functions relating to the player's character
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
  public:
    int getStr();
    int getIntel();
    int getWisd();
    int getDext();
    int getCons();
    int getChar();
    int getAge();
    int getWeight();
    string getName();
    char getGender();

  private:
    int str, intel, wisd, dext, cons, charisma, age, weight, level, exp, mana,
      gold;
    string name, gender;
};

#endif