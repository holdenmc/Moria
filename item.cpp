/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
item.cpp - implementations for item.h

indicators
1 - str
2 - intel
3 - wisd 
4 - dext 
5 - cons 
6 -charisma

types
1 - weapon
2 - helmet
3 - body
4 - legs
5 - shield
 */

#include <iomanip>
#include <iostream>
#include <string>
#include "item.h"


using namespace std;

//Default Constructor
Item::Item() {
  boost = 0;
  indicator = DEF_INDIC;
  type = DEF_TYPE;
  name = "Fists";
  equipped = false;
}

Item::Item(string i_name, int i_boost, int i_indicator, int i_type) {
  name = i_name;
  boost = i_boost;
  type = i_type;
  indicator = i_indicator;
  equipped = false;
}

string Item::getName() {
  return name;
}

int Item::getBoost() {
  return boost;
}

int Item::getIndicator() {
  return indicator;
}

int Item::getType() {
  return type;
}

bool Item::getEquip() {
  return equipped;
}

void Item::setEquip(bool i_equipped) {
  equipped = i_equipped;
}

void Item::equip(Player* thePlayer) {

  if (equipped == true) {
    equipped = false;
    return;
  } 

  //Check for equipped
  Item curr;
  vector<Item> list = thePlayer->getItems();
  for (unsigned int i = 0; i < list.size(); i++) {
    
    curr = list.at(i);
    //Checks if there is currently one of that type equipped
    if (curr.getType() == type) {
      if (curr.getEquip()) {
        if (name.compare(curr.getName()) != 0) { //Checks that its not the currItem
          curr.setEquip(false);
          equipped = true;
          return;
        }
      }
    
    }
  } 
  if (equipped == false) {
    equipped = true;
  }

  

}
