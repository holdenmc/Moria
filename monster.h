/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
monster.h - controls monsters that exist in dungeons, contains some preset
  monsters and some more randomly generated common ones
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <string>

//weak consts
#define WEAK_HEALTH_MIN 9
#define WEAK_HEALTH_RANGE 2
#define WEAK_STR_MIN 10
#define WEAK_STR_RANGE 2
//medium consts
#define MED_HEALTH_MIN 18
#define MED_HEALTH_RANGE 4
#define MED_STR_MIN 14
#define MED_STR_RANGE 4
//high consts
#define HIGH_HEALTH_MIN 25
#define HIGH_HEALTH_RANGE 5
#define HIGH_STR_MIN 18
#define HIGH_STR_RANGE 4
//boss specifics
#define WALRUS_HEALTH 13
#define WALRUS_STRENGTH 13
#define UNICORN_HEALTH 20
#define UNICORN_STRENGTH 18
#define SMALLDRAGON_HEALTH 25
#define SMALLDRAGON_STRENGTH 21
#define MOTHER_HEALTH 25
#define MOTHER_STRENGTH 25
#define DRAGON_HEALTH 35
#define DRAGON_STRENGTH 28
#define BALROG_HEALTH 45
#define BALROG_STRENGTH 38


using namespace std;

class Monster {
  public:
    enum monsters {
      Worm = 0, Rock, Goblin, Bandit, //basic/weaker enemies
      Elf, Dog, Wolf, Jackal, BanditLeader, //medium
      Gremlin, Gargoyle, Leprechaun, Nymph, //strong
      Walrus, Unicorn, SmallDragon, Dragon, MotherDragon, Balrog //bosses for each level
    };
    Monster(enum monsters theMonster);
    //location of monster in tiles[][], publicly accessible since these are
    //really dependent on the Map state, let the map have access to control this
    int row, col; 
    char getName();
    int getHealth();
    int getStr();
    void hitForDamage(int dmg);

  private:
    enum monsters monsterType;
    int health, strength;
    char name;
    void makeWeakMonster(enum monsters theMonster);
    void makeMedMonster(enum monsters theMonster);
    void makeHighMonster(enum monsters theMonster);
    void makeBoss(enum monsters theMonster);
};

#endif