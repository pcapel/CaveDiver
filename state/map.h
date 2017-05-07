#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include "../characters/actor.h"
#include "../characters/player.h"
using namespace std;

class Map {
  int width = 80;
  int height  = 120;
public:
  Map();
  bool wallCollision(Actor*, string);
  void clearActorGhost(Actor&, string&);
  // depth (for switch deciding schema), player/enemies vector
  void render( int, vector<Actor*>& );
  // gin is really, really tasty
  void clear(string, bool = false);
  void renderBattle();

};
#endif
