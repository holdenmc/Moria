/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
player.cpp - implementations for player.h
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "player.h"
#include "item.h"
#include "monster.h"

using namespace std;

// Default player constructor. If you didn't give inputs, you know nothing.
Player::Player() {
  name = "John Snow";
  gender = 'm';
  str = DEF_STAT;
  intel = DEF_STAT;
  health = DEF_HEALTH + 2*DEF_STAT;
  dext = DEF_STAT;
  cons = DEF_STAT;
  charisma = DEF_STAT;
  age = DEF_AGE;
  height = DEF_HEIGHT_M;
  weight = DEF_WEIGHT_M;
  healthPots = 1;
  
  level = 1;
  expe = 0;
  mana = DEF_MANA;
  gold = DEF_GOLD;

  base_str = str; 
  base_intel = intel; 
  base_dext = dext; 
  base_cons = cons; 
  base_char = charisma;
  max_health = health;
  base_health = DEF_HEALTH;

}

Player::Player(int i_str, int i_intel, int i_dext, int i_cons, 
        int i_charisma, int i_age, int i_height, int i_weight,
        string i_name, char i_gender) {
  name = i_name;

  if (i_gender == MALE || i_gender == FEMALE) {
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

  health = 2*cons + DEF_HEALTH; //Health is a calculated field
  max_health = health;
  base_health = DEF_HEALTH;

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
  level = 1;
  expe = 0;
  mana = DEF_MANA * intel/8;
  gold = DEF_GOLD + (charisma - 8)*10;

  healthPots = 1;
  if (charisma > 15) {
    healthPots++;
  }

  base_str = str; 
  base_intel = intel; 
  base_dext = dext; 
  base_cons = cons; 
  base_char = charisma;

}

int Player::getStr() {
  return str;
}

int Player::getIntel() {
  return intel;
}

int Player::getHealth() {
  return health;
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
  return expe;
}

int Player::getGold() {
  return gold;
}

int Player::getMana() {
  return mana;
}

vector<Item> Player::getItems() {
  return items;
}

int Player::getHealthPots() {
  return healthPots;
}

int Player::getMaxHealth() {
  return max_health;
}

void Player::incrExp(int addedExp) {
  expe += addedExp;

  //Levels up every 100 points
  if (expe >= LEVELEXP) {
    expe = 0; //reset exp
    levelUp();
  }

}

void Player::changeMana(int manaChange) {
  mana += manaChange;
}

void Player::changeGold(int moneyChange) {
  gold += moneyChange;
}

void Player::setItems(vector<Item> currItemList) {
  items = currItemList;
}

void Player::addItem(Item newItem) {
  items.push_back(newItem);
}

void Player::removeItem(string removeName) {
  unsigned int i;
  vector<Item> newItemList;
  for (i = 0; i < items.size(); i++) {
    if (removeName.compare(items.at(i).getName()) != 0) {
      newItemList.push_back(items.at(i));
    }
  }
  items = newItemList;
}

void Player::drinkHealthPot() {
  if (health == max_health) {
    return;
  }

  if (healthPots > 0) {
    health += 10;
    if (health > max_health) {
      health = max_health;
    }
    healthPots--;
  }
}

void Player::setHealthPot(int numPots) {
  healthPots = numPots;
}

void Player::refreshStats() {

  int str_boost = 0;
  int int_boost = 0;
  int cons_boost = 0;
  int char_boost = 0;
  int dext_boost = 0;

  for (unsigned int i = 0; i < items.size(); i++) {
    if (items.at(i).getEquip()) {
      switch(items.at(i).getIndicator()) {

        /*indicators
        1 - str
        2 - intel
        3 - dext 
        4 - cons 
        5 -charisma */

        case 1: str_boost += items.at(i).getBoost();
                break;

        case 2: int_boost += items.at(i).getBoost();
                break;

        case 3: dext_boost += items.at(i).getBoost();
                break;

        case 4: cons_boost += items.at(i).getBoost();
                break;

        case 5: char_boost += items.at(i).getBoost();
                break;

      }
    }
  }

  str = base_str + str_boost;
  intel = base_intel + int_boost;
  cons = base_cons + cons_boost;
  charisma = base_char + char_boost;
  dext = base_dext + dext_boost;
  max_health = base_health + cons*2;
  mana = DEF_MANA * intel/8;


}

void Player::levelUp() {
  base_health++;
  health++;
  level++;

  cout << "Level up: choose what stat you would like to increase by 1:" << endl
    << "A - strength" << endl << "B - constitution" << endl
    << "C - intelligence" << endl << "D - dexterity" << endl
    << "E - charisma" << endl;

  char choice;
  cin >> choice;
  while (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D'
      && choice != 'E') {
    cout << "Invalid choice - try again: ";
    cin >> choice;
  }

  if (choice == 'A') {
    base_str++;
  } else if (choice == 'B') {
    base_cons++;
  } else if (choice == 'C') {
    base_intel++;
  } else if (choice == 'D') {
    base_dext++;
  } else {
    base_char++;
  }

  refreshStats();
}

int Player::battleMonster(Monster* theMonster, bool playerFirst) {
  srand(time(NULL));
  if (playerFirst) {
    theMonster->hitForDamage(getStr());
    if (theMonster->getHealth() <= 0) {
      incrExp(EXP_CONST);
      return MONSTER_DIE;
    }

    int random = rand() % MISS_RANGE; // dex is % chance of enemy missing
    if (random < MISS_RANGE - dext) {
      hitForDamage(theMonster->getStr());
      if (health <= 0) {
        return PLAYER_DIE;
      }
    }

    return NO_DEATH;
  } else {
    int random = rand() % MISS_RANGE; // dex is % chance of enemy missing
    if (random < MISS_RANGE - dext) {
      hitForDamage(theMonster->getStr());
      if (health <= 0) {
        return PLAYER_DIE;
      }
    }

    theMonster->hitForDamage(getStr());
    if (theMonster->getHealth() <= 0) {
      incrExp(EXP_CONST);
      return MONSTER_DIE;
    }

    return NO_DEATH;
  }
}

void Player::hitForDamage(int dmg) {
  if (dmg - cons > 0) {
    health-= (dmg - cons);
  }
}
