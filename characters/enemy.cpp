#include <string>
#include <iostream>
#include "enemy.h"
#include "actor.h"
using namespace std;

Enemy::Enemy (
  int x,
  int y,
  int lvl,
  int hp,
  int str,
  int eva,
  int atkT,
  double eva_f,
  string nm,
  string desc) : Actor(x, y, lvl, hp, str, eva, atkT, eva_f) {
  name = nm;
  description = desc;
}
string Enemy::getName() {
  return this->name;
}
string Enemy::getDescription(){
  return this->description;
}
