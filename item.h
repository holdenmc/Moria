/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
item.h - controls the items class and everything to do with them

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

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "player.h"


using namespace std;

class Item {
  public:
    Item();
    Item(string i_name, int i_boost, int i_indicator, int i_type);

    string getName();
    int getBoost();
    int getIndicator();
    int getType();
    bool getEquip();

    void equip(Player* thePlayer);

  private:
    int boost;
    int indicator; //Determines which stat it increases
    int type; //Determines the type (so you can only have one weapon)
    string name;
    bool equipped;

};



#endif