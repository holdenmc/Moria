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

int Monster::getHealth() {
  return health;
}

int Monster::getStr() {
  return strength;
}

void Monster::hitForDamage(int dmg) {
  health-= dmg;
}

void Monster::makeWeakMonster(enum monsters theMonster) {
  srand(time(NULL));
  health = rand() % WEAK_HEALTH_RANGE + WEAK_HEALTH_MIN;
  strength = rand() % WEAK_STR_RANGE + WEAK_STR_MIN;

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
  health = rand() % MED_HEALTH_RANGE + MED_HEALTH_MIN;
  strength = rand() % MED_STR_RANGE + MED_STR_MIN;

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
  health = rand() % HIGH_HEALTH_RANGE + HIGH_HEALTH_MIN;
  strength = rand() % HIGH_STR_RANGE + HIGH_STR_MIN;

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
    name = 'W';
  } else if (theMonster == Unicorn) {
    health = UNICORN_HEALTH;
    strength = UNICORN_STRENGTH;
    name = 'U';
  } else if (theMonster == SmallDragon) {
    health = SMALLDRAGON_HEALTH;
    strength = SMALLDRAGON_STRENGTH;
    name = 'S';
  } else if (theMonster == Dragon) {
    health = DRAGON_HEALTH;
    strength = DRAGON_STRENGTH;
    name = 'D';
  } else if (theMonster == MotherDragon) {
    health = MOTHER_HEALTH;
    strength = MOTHER_STRENGTH;
    name = 'M';
  } else {
    health = BALROG_HEALTH;
    strength = BALROG_STRENGTH;
    name = 'B';
  }
}