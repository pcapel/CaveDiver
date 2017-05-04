#include <string>
#include "enemy.h"
#include "player.h"
#include <iostream>
using namespace std;

Enemy::Enemy(int lvl, int hp, int str, int eva, double eva_f, string nm, string desc, string atk_type) {
  level = lvl;
  health = hp;
  strength = str;
  attack_type = atk_type;
  evasion = eva;
  stats[0] = lvl;
  stats[1] = hp;
  stats[2] = str;
  stats[3] = eva;
  evasion_fraction = eva_f;
  name = nm;
  description = desc;
}
void Enemy::attack(Player& p) {
  p.takeDamage(this->strength, this->attack_type);
  return ;
}
string Enemy::getName() {
  return this->name;
}
string Enemy::getDescription(){
  return this->description;
}
int* Enemy::getStats() {
  return this->stats;
}
