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
#define AGE_MIN       1
#define AGE_MAX       99
#define WEIG_MAX      300
#define WEIGH_MIN     80
#define HEIG_MAX      96
#define HEIG_MIN      36
#define LEVELEXP      100
#define DEF_STAT      8
#define DEF_AGE       20
#define DEF_HEIGHT_M  70
#define DEF_HEIGHT_F  64
#define DEF_WEIGHT_M  180
#define DEF_WEIGHT_F  135
#define DEF_GOLD      300
#define DEF_MANA      50
#define DEF_HEALTH    10
#define NO_DEATH      0
#define MONSTER_DIE   1
#define PLAYER_DIE    2
#define EXP_CONST     10
#define MISS_RANGE    100
#define MAX_STAT_INIT 20
#define CONS_MULT     2
#define MANA_FACTOR   8
#define GOLD_CHAR_DIF 8
#define GOLD_MULT     10
#define CHAR_POTBONUS 15
#define HPOT_RESTORE  10

#include <string>
#include <vector>
#include "monster.h"


using namespace std;
class Item;
class Player {
  public:
    //Default constructor
    Player();
    //Real constructor
    Player(int i_str, int i_intel, int i_dext, int i_cons, 
        int i_charisma, int i_age, int i_height, int i_weight,
        string i_name, char i_gender);

    //OH MY GOD SO MANY GETTERS WOWOWOWOWOWOWOW
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

    //These modify their respective stat by the input value
    void incrExp(int addedExp);
    void changeMana(int manaChange);
    void changeGold(int moneyChange);

    //Methods for manipulating the players items
    void addItem(Item newItem);
    void removeItem(string removeName);
    void setItems(vector<Item> currItemList);

    //Changes stats to deal with equipment
    void refreshStats();

    void drinkHealthPot();
    void setHealthPot(int numPots);

    //to be called when the player is neighboring a monster in a dungeon;
    //allows player to attack monster first and then monster attack back
    //if playerFirst = true; vice versa for false
    //returns 0 if neither monster nor player died, 1 if monster died, 2 if
    //player died
    int battleMonster(Monster* theMonster, bool playerFirst);
    //based on player cons, deals damage if any damage is dealt to player
    void hitForDamage(int dmg);



  private:
    int str, intel, health, dext, cons, charisma, age, height, weight, level,
     expe, mana, gold, healthPots, max_health;
    int base_str, base_intel, base_dext, base_cons, base_char, base_health;
    string name;
    char gender;
    vector<Item> items;
    //Method that handles the menu for when a player levels up.
    void levelUp();
};


#endif