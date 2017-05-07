#ifndef ACTOR_H
#define ACTOR_H
#include <string>
using namespace std;

class Actor {
protected:
  bool dead = false;
  int xpos = 49;
  int ypos = 12;
  int prevX = 49;
  int prevY = 12;

  int level, health, strength, evasion, attack_type;
  int stats[4];

  double evasion_fraction;
public:
  // xpos, ypos, level, health, strength, evasion, attack_type, evasion_fraction
  Actor(int, int, int, int, int, int, int, double);
  int getHealth();
  int getLevel();
  int getEvasion();
  int* getStats();

  int getXPos();
  int getYPos();

  int getPrevX();
  int getPrevY();

  int getDirection();

  bool isDead();

  void acceptAction(int);
  void takeDamage(int, int);
  void die();

  void setHealth(int);
  void setLevel(int);
  void setEvasion(int);
  void setXPos(int);
  void setYPos(int);
  void setPrevY(int);
  void setPrevX(int);

  void move(char);
  void attack(Actor&);
};

#endif
