#ifndef CHEST_H
#define  CHEST_H
#include "../items/item.h"
#include "container.h"

class Chest : public Container {
protected:
  int xpos;
  int ypos;
public:
  Chest(int, int);
  void setYPos(int);
  void setXPos(int);
  int getXPos();
  int getYPos();
};

#endif
