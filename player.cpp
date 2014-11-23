/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
player.cpp - implementations for player.h
 */

#include <string>
#include "player.h"

// Default player constructor. If you didn't give inputs, you know nothing.
Player::Player() {
  name = "John Snow";
  gender = 'm';
  str = 5;
  intel = 5;
  wisd = 5;
  dext = 5;
  cons = 5;
  charisma = 5;
  age = 20;
  height = 72;
  weight = 155;
  
  level = 1;
  exp = 0;
  mana = 50;
  gold = 200;

}

Player::Player(int i_str, int i_intel, int i_wisd, int i_dext, int i_cons, 
        int i_charisma, int i_age, string i_name, char i_gender) {
  name = i_name;
  if () {
    gender = i_gender;
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