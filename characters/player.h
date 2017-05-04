#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
  bool dead = false;
public:
  bool inBattle = false;
  int health;
  Player(int);
  void takeDamage(int, std::string);
  void die();
  bool isDead();
  int getHealth();
  void setHealth(int);
};
#endif
