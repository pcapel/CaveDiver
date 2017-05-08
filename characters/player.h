#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "actor.h"

class Player: public Actor {
  bool isGod = false;
  bool isSuper = false;
  int depth = 0;
  bool inBattle = false;
public:
  // from Actor class
  // xpos, ypos, level, health, strength, evasion, attack_type, evasion_fraction
  // player specific
  // depth
  Player(int, int, int, int, int, int, int, double, int);
  int getDepth();

  bool battleStatus();

  void toggleInBattle();
  void toggleGod();
  void toggleSuperStrong();
  void move(char);
};
#endif
