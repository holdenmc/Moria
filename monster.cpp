/*
Conor Ryan
Holden McGinnis
CIS 190 Final Project
monster.cpp - implementation for monster.cpp
 */

using namespace std;

#include <time.h>
#include <cstdlib>
#include "monster.h"

Monster::Monster(enum monsters theMonster) {
  monsterType = theMonster;
  if (theMonster <= Bandit) {
    makeWeakMonster(theMonster);
  } else if (theMonster <= BanditLeader) {
    makeMedMonster(theMonster);
  } else if (theMonster <= Nymph) {
    makeHighMonster(theMonster);
  } else {
    makeBoss(theMonster);
  }
}

char Monster::getName() {
  return name;
}

void Monster::makeWeakMonster(enum monsters theMonster) {
  srand(time(NULL));
  health = rand() % WEAK_HEALTH_MIN + WEAK_HEALTH_RANGE;
  strength = rand() % WEAK_STR_MIN + WEAK_STR_RANGE;
  gold = rand() % WEAK_GOLD_RANGE + WEAK_GOLD_MIN;

  if (theMonster == Worm) {
    name = 'w';
  } else if (theMonster == Rock) {
    name = 'r';
  } else if (theMonster == Goblin) {
    name = 'g';
  } else {
    name = 'b';
  }
}

void Monster::makeMedMonster(enum monsters theMonster) {
  srand(time(NULL));
  health = rand() % MED_HEALTH_MIN + MED_HEALTH_RANGE;
  strength = rand() % MED_STR_MIN + MED_STR_RANGE;
  gold = rand() % MED_GOLD_RANGE + MED_GOLD_MIN;

  if (theMonster == Elf) {
    name = 'e';
  } else if (theMonster == Dog) {
    name = 'd';
  } else if (theMonster == Wolf) {
    name = 'w';
  } else if (theMonster == Jackal) {
    name = 'j';
  } else {
    name = 'l';
  }
}

void Monster::makeHighMonster(enum monsters theMonster) {
  srand(time(NULL));
  health = rand() % HIGH_HEALTH_MIN + HIGH_HEALTH_RANGE;
  strength = rand() % HIGH_STR_MIN + HIGH_STR_RANGE;
  gold = rand() % HIGH_GOLD_RANGE + HIGH_GOLD_MIN;

  if (theMonster == Gremlin) {
    name = 'G';
  } else if (theMonster == Gargoyle) {
    name = 'Y';
  } else if (theMonster == Leprechaun) {
    name = 'L';
  } else {
    name = 'N';
  }
}

void Monster::makeBoss(enum monsters theMonster) {
  if (theMonster == Walrus) {
    health = WALRUS_HEALTH;
    strength = WALRUS_STRENGTH;
    gold = BOSS_BASE_GOLD + WALRUS_HEALTH;
    name = 'W';
  } else if (theMonster == Unicorn) {
    health = UNICORN_HEALTH;
    strength = UNICORN_STRENGTH;
    gold = BOSS_BASE_GOLD + UNICORN_HEALTH;
    name = 'U';
  } else if (theMonster == SmallDragon) {
    health = SMALLDRAGON_HEALTH;
    strength = SMALLDRAGON_STRENGTH;
    gold = BOSS_BASE_GOLD + SMALLDRAGON_HEALTH;
    name = 's';
  } else if (theMonster == Dragon) {
    health = DRAGON_HEALTH;
    strength = DRAGON_STRENGTH;
    gold = BOSS_BASE_GOLD + DRAGON_HEALTH;
    name = 'D';
  } else if (theMonster == MotherDragon) {
    health = MOTHER_HEALTH;
    strength = MOTHER_STRENGTH;
    gold = BOSS_BASE_GOLD + MOTHER_HEALTH;
    name = 'M';
  } else {
    health = BALROG_HEALTH;
    strength = BALROG_STRENGTH;
    gold = BOSS_BASE_GOLD + BALROG_HEALTH;
    name = 'B';
  }
}