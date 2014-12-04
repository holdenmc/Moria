/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
item.h - controls the items class and everything to do with them

indicators
1 - str
2 - intel
3 - dext 
4 - cons 
5 -charisma

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

#define DEF_INDIC 1
#define DEF_TYPE 1

#define STR 1
#define INTEL 2
#define DEXT 3
#define CONS 4
#define CHARIS 5
#define WEAPON 1
#define HELMET 2
#define BODY 3
#define LEGS 4
#define SHIELD 5

#define SM_BOOST 1
#define MED_BOOST 2
#define MEDH_BOOST 3
#define HIGH_BOOST 4
#define VHI_BOOST 6

#define POT_PRICE 100
#define PRICE_LOW 250
#define PRICE_MED 700
#define PRICE_HIGH 1500
#define PRICE_VHI 2500
#define PRICE_VVHI 5000

#define VEST_PRICE 500
#define CHNMAIL_PRICE 1200


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

    void setEquip(bool i_equipped);

    void equip(Player* thePlayer);

  private:
    int boost;
    int indicator; //Determines which stat it increases
    int type; //Determines the type (so you can only have one weapon)
    string name;
    bool equipped;

};



#endif