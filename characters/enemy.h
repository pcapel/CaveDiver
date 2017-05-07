#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "actor.h"
using namespace std;

class Enemy: public Actor {
  string name;
  string description;
  string attack_type;
public:
  // from Actor class
  // xpos, ypos, level, health, strength, evasion, attack_type, evasion_fraction
  // enemy specific
  // name, description
  Enemy(int, int, int, int, int, int, int, double, string, string);

  string getName();
  string getDescription();
};
#endif
