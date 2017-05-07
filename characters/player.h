#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "actor.h"

class Player: public Actor {
  bool isGod = false;
  bool isSuper = false;
  int depth = 0;
public:
  bool inBattle = false;
  // from Actor class
  // xpos, ypos, level, health, strength, evasion, attack_type, evasion_fraction
  // player specific
  // depth
  Player(int, int, int, int, int, int, int, double, int);
  int getDepth();

  void toggleGod();
  void toggleSuperStrong();
  void move(char);
};
#endif
