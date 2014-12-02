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
#define DEF_HEALTH 10

#include <string>
#include <vector>
#include "monster.h"


using namespace std;
class Item;
class Player {
  public:
    Player();
    Player(int i_str, int i_intel, int i_dext, int i_cons, 
        int i_charisma, int i_age, int i_height, int i_weight,
        string i_name, char i_gender);

    int getStr();
    int getIntel();
    int getHealth();
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
    vector<Item> getItems();
    int getHealthPots();
    int getMaxHealth();


    void incrExp(int addedExp);
    void changeMana(int manaChange);
    void changeGold(int moneyChange);
    void addItem(Item newItem);
    void removeItem(string removeName);
    void refreshStats();
    void drinkHealthPot();
    void setItems(vector<Item> currItemList);
    void setHealthPot(int numPots);

    //to be called when the player is neighboring a monster in a dungeon;
    //allows player to attack monster first and then monster attack back
    //if playerFirst = true; vice versa for false
    void battleMonster(Monster* theMonster, bool playerFirst);



  private:
    int str, intel, health, dext, cons, charisma, age, height, weight, level,
     exp, mana, gold, healthPots, max_health;
    int base_str, base_intel, base_dext, base_cons, base_char;
    string name;
    char gender;
    vector<Item> items;
    void levelUp();
};


#endif