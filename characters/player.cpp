#include <iostream>
#include <string>
#include "player.h"
#include "actor.h"
using namespace std;

const int w = 119;
const int a = 97;
const int s = 115;
const int d = 100;

Player::Player(
  int x,
  int y,
  int lvl,
  int hp,
  int str,
  int eva,
  int atkT,
  double eva_f,
  int depth) : Actor(x, y, lvl, hp, str, eva, atkT, eva_f) {
    this->depth = depth;
}

int Player::getDepth() {
  return depth;
}

void Player::toggleGod() {
  isGod = !isGod;
}

void Player::toggleSuperStrong() {
  isSuper = !isSuper;
}

void Player::move(char d) {
  Actor::move(d);
  if (prevY == 1 && d == w) {
    depth += 1;
  }
}
