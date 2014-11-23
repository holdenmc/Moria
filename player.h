/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
player.h - controls all data and functions relating to the player's character

Str, intel, wisd, dext, cons, charisma are all capped at 20, min at 1
 */

#ifndef PLAYER_H
#define PLAYER_H

#define MALE 'm'
#define FEMALE 'f'
#define LEVELEXP 100
#define DEF_STAT 8
#define DEF_AGE 20
#define DEF_HEIGHT_M 70
#define DEF_HEIGHT_F 64
#define DEF_WEIGHT_M 180
#define DEF_WEIGHT_F 135
#define DEF_GOLD 200
#define DEF_MANA 50

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
    int getLevel();
    int getEXP();
    int getGold();
    int getMana();


    void incrExp(int addedExp);
    void changeMana(int manaChange);
    void changeGold(int moneyChange);



  private:
    int str, intel, wisd, dext, cons, charisma, age, height, weight, level,
     exp, mana, gold;
    string name;
    char gender;
    void LevelUp();
};

#endif