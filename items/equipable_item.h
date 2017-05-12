#ifndef EQ_ITEM_H
#define  EQ_ITEM_H
#include "item.h"
#include <string>

class EquipableItem : public Item {
protected:
  /*
  I keep running across the desire to create a type for these
  I may give that more thought, just wanted to get it in writing
  it would make passing setters and getters a little more streamlined
  I think.
  */
  int strengthBuff;
  int evasionBuff;
  int healthBuff;
  int attackBuff;
  int typeBuff;
public:
  EquipableItem(std::string);
  void equip();
  void degrade();
  void repair();
  void setBuff();
};


#endif
