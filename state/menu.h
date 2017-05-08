#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>

class Menu {
protected:
  vector<void(*)()> optionCallbacks;
  vector<string> options;
  string borderChar;
  string borderCharTop;
  string borderCharBottom;
  string borderCharLeft;
  string borderCharRight;
  string separatorChar;
  string menuScheme[];
  string cursor;

  int height, width;
  vector<int> sepYIndices;
public:

  Menu();

  int getHeight();
  int getWidth();
  vector<int> getSepYIndices();

  void setCursor(string);
  void addOption(string);
  void removeOption(string);
  // bools are top, bottom, left, right.  single function to set any value
  void setBorderChar(string, bool = true, bool = true, bool = true, bool = true);
  void setSeparatorChar(string);
  void setMenuScheme(string*);
  void setHeight(int);
  void setWidth(int);
  void addSeparatorYIndex(int);
  void show();
  // accept different types to have movement
  void moveCursor(char);
  void moveCursor(int);
  void moveCursor(string);
  void attachCallback(void(*)());
};

#endif
