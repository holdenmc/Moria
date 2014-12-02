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
#define WEAK_HEALTH_MIN 4
#define WEAK_HEALTH_RANGE 3
#define WEAK_STR_MIN 2
#define WEAK_STR_RANGE 2
#define WEAK_GOLD_MIN 10
#define WEAK_GOLD_RANGE 20
//medium consts
#define MED_HEALTH_MIN 7
#define MED_HEALTH_RANGE 4
#define MED_STR_MIN 4
#define MED_STR_RANGE 4
#define MED_GOLD_MIN 25
#define MED_GOLD_RANGE 25
//high consts
#define HIGH_HEALTH_MIN 10
#define HIGH_HEALTH_RANGE 5
#define HIGH_STR_MIN 6
#define HIGH_STR_RANGE 4
#define HIGH_GOLD_MIN 40
#define HIGH_GOLD_RANGE 35
//boss specifics
#define WALRUS_HEALTH 9
#define WALRUS_STRENGTH 5
#define UNICORN_HEALTH 15
#define UNICORN_STRENGTH 5
#define SMALLDRAGON_HEALTH 13
#define SMALLDRAGON_STRENGTH 9
#define MOTHER_HEALTH 14
#define MOTHER_STRENGTH 10
#define DRAGON_HEALTH 16
#define DRAGON_STRENGTH 9
#define BALROG_HEALTH 25
#define BALROG_STRENGTH 13
#define BOSS_BASE_GOLD 75


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

  private:
    enum monsters monsterType;
    int health, strength, gold;
    char name;
    void makeWeakMonster(enum monsters theMonster);
    void makeMedMonster(enum monsters theMonster);
    void makeHighMonster(enum monsters theMonster);
    void makeBoss(enum monsters theMonster);
};

#endif