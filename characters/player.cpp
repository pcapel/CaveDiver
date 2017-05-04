#include "player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(int hp) {
  health = hp;
}

void Player::takeDamage(int attack, string damage_type) {
  int modifier = 0;
  const string types[3] = {"physical","magical","psychic"};
  int i;
  for(i = 0; i < 3; i++) {
    if (damage_type.compare(types[i]) == 0) break;
  }
  switch (i) {
    case 0: // modifications are modulated based on attack type
      setHealth(health - attack);
      break;
  }
  if(health < 0) die();
}

void Player::die() {
  dead = 1;
}

bool Player::isDead() {
  return dead;
}

int Player::getHealth() {
  return health;
}

void Player::setHealth(int health) {
  this->health = health;
  return ;
}
