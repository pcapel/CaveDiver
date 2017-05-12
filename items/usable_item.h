#ifndef USABLE_ITEM_H
#define  USABLE_ITEM_H
#include <string>
#include "item.h"
#include "../characters/actor.h"

class UsableItem : public Item {
protected:
public:
  UsableItem();
  ~UsableItem();
  void applyEffect(Actor&);
};

#endif
