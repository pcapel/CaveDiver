#include <string>
#include <iostream>
#include "../items/item.h"

class Container {
protected:
  vector<Item> items;
public:
  void addItem(Item);
  void listItems();
  Item getItem();
};
