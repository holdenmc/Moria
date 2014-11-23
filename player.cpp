/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
player.cpp - implementations for player.h
 */

#include <iomanip>
#include <iostream>
#include <string>
#include "player.h"

using namespace std;

// Default player constructor. If you didn't give inputs, you know nothing.
Player::Player() {
  name = "John Snow";
  gender = 'm';
  str = DEF_STAT;
  intel = DEF_STAT;
  wisd = DEF_STAT;
  dext = DEF_STAT;
  cons = DEF_STAT;
  charisma = DEF_STAT;
  age = DEF_AGE;
  height = DEF_HEIGHT_M;
  weight = DEF_WEIGHT_M;
  
  level = 1;
  exp = 0;
  mana = DEF_MANA;
  gold = DEF_GOLD;

}

Player::Player(int i_str, int i_intel, int i_wisd, int i_dext, int i_cons, 
        int i_charisma, int i_age, int i_height, int i_weight,
        string i_name, char i_gender) {
  name = i_name;

  if (gender == MALE || gender == FEMALE) {
    gender = i_gender;
  } else {
    cout << "CHOSE AN INVALID GENDER";
    //Goes to default gender;
    gender = FEMALE;
  }
  
  if(i_str <= 20 && i_str > 0) {
    str = i_str;
  } else {
    cout << "CHOSE AN INVALID STRENGTH";
    //Goes to default
    str = DEF_STAT;
  }

  if(i_intel <= 20 && i_intel > 0) {
    intel = i_intel;
  } else {
    cout << "CHOSE AN INVALID INTELLIGENCE";
    //Goes to default
    intel = DEF_STAT;
  }

  if(i_wisd <= 20 && i_wisd > 0) {
    wisd = i_wisd;
  } else {
    cout << "CHOSE AN INVALID WISDOM";
    //Goes to default
    wisd = DEF_STAT;
  }

  if(i_dext <= 20 && i_dext > 0) {
    dext = i_dext;
  } else {
    cout << "CHOSE AN INVALID DEXTERITY";
    //Goes to default
    dext = DEF_STAT;
  }

  if(i_cons <= 20 && i_cons > 0) {
    cons = i_cons;
  } else {
    cout << "CHOSE AN INVALID CONSTITUTION";
    //Goes to default
    cons = DEF_STAT;
  }

  if(i_charisma <= 20 && i_charisma > 0) {
    charisma = i_charisma;
  } else {
    cout << "CHOSE AN INVALID Charisma";
    //Goes to default
    charisma = DEF_STAT;
  }

  if(i_age <= 99 && i_age > 0) {
    age = i_age;
  } else {
    cout << "CHOSE AN INVALID AGE";
    //Goes to default
    age = DEF_AGE;
  }

  if(i_weight <= 300 && i_weight >= 80) {
    weight = i_weight;
  } else {
    if (gender == MALE) {
      weight = DEF_WEIGHT_M;
    } else {
      weight = DEF_WEIGHT_F;
    }
  }

  if(i_height <= 96 && i_height >= 36) {
    height = i_height;
  } else {
    if (gender == MALE) {
      height = DEF_HEIGHT_M;
    } else {
      height = DEF_HEIGHT_F;
    }
  }

}

int Player::getStr() {
  return str;
}

int Player::getIntel() {
  return intel;
}

int Player::getWisd() {
  return wisd;
}

int Player::getDext() {
  return dext;
}

int Player::getCons() {
  return cons;
}

int Player::getChar() {
  return charisma;
}

//In inches
int Player::getAge() {
  return age;
}

int Player::getHeight() {
  return height;
}

int Player::getWeight() {
  return weight;
}

string Player::getName() {
  return name;
}

char Player::getGender() {
  return gender;
}

int Player::getLevel() {
  return level;
}

int Player::getEXP() {
  return exp;
}

int Player::getGold() {
  return gold;
}

int Player::getMana() {
  return mana;
}

void Player::incrExp(int addedExp) {
  exp += addedExp;

  //Levels up every 100 points
  if (exp >= level*LEVELEXP) {
    LevelUp();
  }

}

void Player::changeMana(int manaChange) {
  mana += manaChange;
}

void Player::changeGold(int moneyChange) {
  gold += moneyChange;
}

void Player::LevelUp() {
  //THIS NEEDS TO BE DONE
  //Calls some sort of menu where the player hits inputs to choose what stats
  //to upgrade
}


