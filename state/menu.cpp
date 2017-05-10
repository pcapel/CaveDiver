#include <string>
#include <vector>
#include <iostream>
#include "menu.h"
using namespace std;

Menu::Menu() {
  /*
  maybe a switch that switches on menu types
  that'd be pretty sweet.
  */
}

int Menu::getHeight(){
  return height;
}
int Menu::getWidth() {
  return width;
}
vector<int> Menu::getSepYIndices() {
  return sepYIndices;
}

void Menu::setCursor(string newCursor) {
  cursor = newCursor;
}
void Menu::addOption(string newOption){
  options.push_back(newOption);
}
void Menu::removeOption(string){
  //some logic
}
// bools are top, bottom, left, right.  single function to set any value
void Menu::setBorderStr(string border, bool top, bool bottom, bool left, bool right){
  if (top) {
    borderStrTop = border;
  }
  if(bottom) {
    borderStrBottom = border;
  }
  if(left) {
    borderStrLeft = border;
  }
  if(right) {
    borderStrRight = border;
  }
}
void Menu::setSeparatorStr(string newStr){
  separatorStr = newStr;
}
void Menu::setMenuScheme(string* newScheme, int schemeH, int schemeW) {
  // because the scheme is an array, the height is the length of the array
  // plus 1 because it isn't zero indexed
  for (int i = 0; i < schemeH - 1; i++) {
    menuScheme[i] = newScheme[i];
  }
  height = schemeH;
  width = schemeW;
}
// void setHeight(int){
//
// }
// void setWidth(int){
//
// }
void Menu::addSeparatorYIndex(int){

}
void Menu::show(){
  /*
  uses the instance scheme to draw out the menu
  */

}
// accept different types to have movement
void Menu::moveCursor(char){

}
void Menu::moveCursor(int){

}
void Menu::moveCursor(string){

}
void Menu::attachCallback(void(*)()){

}
