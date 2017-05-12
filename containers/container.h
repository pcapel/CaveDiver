#ifndef CONTAINER_H
#define  CONTAINER_H

#include <string>
#include <iostream>
#include "../items/item.h"

class Container {
protected:
  vector<Item> items;
public:
  Container();
  void addItem(Item);
  void addItems(vector<Item>);
  void listItems();
  Item getItem();
};
#endif
