/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
item.h - controls the items class and everything to do with them

Str, intel, wisd, dext, cons, charisma are all capped at 20, min at 1
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
  public:
    Item();

  private:
    int statBoost, indicator;
    string name;

};



#endif