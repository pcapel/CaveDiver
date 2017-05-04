#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "player.h"
using namespace std;

class Enemy {
  int level, health, evasion;
  int stats[4];
  double evasion_fraction;
  string name;
  string description;
  string attack_type;
public:
  int strength;
  Enemy(int, int, int, int, double, string, string, string);
  string getName();
  string getDescription();
  int* getStats();
  void attack(Player&);
};
#endif
