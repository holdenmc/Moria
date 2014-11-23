/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
player.h - controls all data and functions relating to the player's character

Str, intel, wisd, dext, cons, charisma are all capped at 20
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
  public:
    Player();
    Player(int i_str, int i_intel, int i_wisd, int i_dext, int i_cons, 
        int i_charisma, int i_age, string i_name, char i_gender);

    int getStr();
    int getIntel();
    int getWisd();
    int getDext();
    int getCons();
    int getChar();
    int getAge();
    int getHeight();
    int getWeight();
    string getName();
    char getGender();


  private:
    int str, intel, wisd, dext, cons, charisma, age, height, weight, level,
     exp, mana, gold;
    string name;
    char gender;
};

#endif