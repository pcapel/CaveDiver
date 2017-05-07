#include <string>
#include <iostream>
#include "actor.h"
using namespace std;

const int w = 119;
const int a = 97;
const int s = 115;
const int d = 100;

Actor::Actor (
    int xpos,
    int ypos,
    int level,
    int health,
    int strength,
    int evasion,
    int attack_type,
    double evasion_fraction) {
  this->xpos = xpos;
  this->ypos = ypos;
  this->prevX = xpos;
  this->prevY = ypos;
  this->level = level;
  this->health = health;
  this->strength = strength;
  this->evasion = evasion;
  this->attack_type = attack_type;
  this->evasion_fraction = evasion_fraction;
  stats[0] = level;
  stats[1] = health;
  stats[2] = strength;
  stats[3] = evasion;
}
void Actor::attack(Actor& a) {
  a.takeDamage(strength, attack_type);
  return ;
}
int* Actor::getStats() {
  return this->stats;
}

void Actor::takeDamage(int attack, int damage_type) {
  int modifier = 0;
  switch (damage_type) {
    case 1: // modifications are modulated based on attack type
      // case 1 is physical attack damage
      setHealth(health - attack);
      break;
  }
  if(health < 0) die();
}

void Actor::acceptAction(int actionChar) {
  //momentarily deprecated
  // switch(actionChar) {
  //   case 0:
  //     cout << "You have selected case: " << actionChar << endl;
  //     Player::move(1);
  //     cout << "Current player depth is: " << Player::getDepth() << endl;
  //     break;
  //   case 1:
  //     cout << "You have selected case: " << actionChar << endl;
  //     Player::move(0);
  //     cout << "Current player depth is: " << Player::getDepth() << endl;
  //     break;
  //   case 3:
  //     cout << "You have selected case: " << actionChar << endl;
  //     break;
  //   case 4:
  //     cout << "You have selected case: " << actionChar << endl;
  //     break;
  //   case 5:
  //     cout << "You have selected case: " << actionChar << endl;
  //     break;
  //   case 6:
  //     cout << "You have selected case: " << actionChar << endl;
  //     break;
  //   case d:
  //     Player::move(d);
  //     break;
  //   case w:
  //     Player::move(w);
  //     break;
  //   case a:
  //     Player::move(a);
  //     break;
  //   case s:
  //     Player::move(s);
  //     break;
  //   case 777:
  //     cout << "God Mode On\n";
  //     Player::toggleGod();
  //     break;
  //   case 666:
  //     cout << "Your deity has been removed\n";
  //     Player::toggleGod();
  //     break;
  //   case 8008:
  //   {
  //     string message;
  //     message = this->isSuper ? "HEFTY HEFTY HEFTY!\n" : "WIMPY WIMPY WIMPY!";
  //     cout << message;
  //     Player::toggleSuperStrong();
  //     break;
  //   }
  //   default:
  //     cout << "Oh crap, I don't have a menu option for " << actionChar << "!!!\n";
  //     break;
  // }
}

int Actor::getDirection() {
  /*
  this method relies on the fact that the screen will only re-render after the
  player has moved, thus releasing us from the PITA of having to track if the
  player has or has not made a move.  If I want to make it so that the enemies
  move independent of the player and rendering occurs regardless, this whole
  methodology goes straight into the toilet.

  returns an integer value representing direction of travel
  1 = north
  2 = east
  3 = south
  4 = west
  0 = failure
  */
  if (xpos - prevX > 0) {
    return 2;
  } else if (xpos - prevX < 0) {
    return 4;
  }
  if(ypos - prevY > 0) {
    return 3;
  }
  else if(ypos - prevY < 0) {
    return 1;
  }
  return 0;
}

void Actor::die() {
  dead = 1;
}

bool Actor::isDead() {
  return dead;
}

int Actor::getHealth() {
  return health;
}

int Actor::getEvasion() {
  return evasion;
}

int Actor::getLevel() {
  return level;
}

int Actor::getXPos() {
  return xpos;
}

int Actor::getYPos() {
  return ypos;
}

int Actor::getPrevY() {
  return prevY;
}

int Actor::getPrevX() {
  return prevX;
}

void Actor::setHealth(int health) {
  this->health = health;
  return ;
}

void Actor::setYPos(int newY) {
  ypos = newY;
}

void Actor::setXPos(int newX) {
  xpos = newX;
}

void Actor::setPrevY(int newPrev) {
  prevY = newPrev;
}

void Actor::setPrevX(int newPrev) {
  prevX = newPrev;
}

void Actor::move(char direction) {
  setPrevY(ypos);
  setPrevX(xpos);
  switch (direction) {
    case w:
      if (ypos > 0) {
        setYPos((ypos - 1) ? (ypos - 1) : 1);
      }
      break;
    case a:
      if (xpos > 0) {
      setXPos((xpos - 1) ? (xpos - 1) : 1);
      }
      break;
    case s:
      if (ypos < 80) { // this shouldn't actually be needed...
      setYPos(ypos + 1 );
      }
      break;
    case d:
      if (xpos) { /// neither should this.  and it's almost midnight...
      setXPos(xpos + 1);
      }
      break;
  }
}
