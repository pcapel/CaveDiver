#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>

class Menu {
protected:
  std::vector<void(*)()> optionCallbacks;
  std::vector<std::string> options;
  std::string borderStr;
  std::string borderStrTop;
  std::string borderStrBottom;
  std::string borderStrLeft;
  std::string borderStrRight;
  std::string separatorStr;
  std::string menuScheme[100]; // 100 is an arbitrary maximum for the menu scheme
  std::string cursor;

  int height, width;
  std::vector<int> sepYIndices;
public:

  Menu();

  int getHeight();
  int getWidth();
  std::vector<int> getSepYIndices();

  void setCursor(std::string);
  void addOption(std::string);
  void removeOption(std::string);
  // bools are top, bottom, left, right.  single function to set any value
  void setBorderStr(std::string, bool = true, bool = true, bool = true, bool = true);
  void setSeparatorStr(std::string);
  void setMenuScheme(std::string*, int, int);
  //void setHeight(int);
  //void setWidth(int);
  void addSeparatorYIndex(int);
  void show();
  // accept different types to have movement
  void moveCursor(char);
  void moveCursor(int);
  void moveCursor(std::string);
  void attachCallback(void(*)());
};

#endif
