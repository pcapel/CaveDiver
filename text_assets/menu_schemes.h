#ifndef MSCHEMES_H
#define  MSCHEMES_H

#include <iostream>
#include <string>
using namespace std;

/*
Menu scheme here would be display label, display value, height, width, separator
Y index, options

The backtick [ `` ] is a special character in the menu class, as it will be used
to split in the data that we want to present inside of the menu
*/
const int BATTLE_SCHEME_WIDTH = 76;
const int BATTLE_SCHEME_HEIGHT = 13;
// separator rows are any that have the separator character that extends
// fully across the width of the menu

const int SEPARATOR_ROWS[] = { 0, 7, 12 };

const string BATTLE_SCHEME[] = {
"###########################################################################",
"#  Enemy- Lvl    `   `                                                    #",
"#  Name:         `   `                                                    #",
"#  Description:  `   `                                                    #",
"#  Health:       `   `                                                    #",
"#  Strength:     `   `                                                    #",
"#  Evasion:      `   `                                                    #",
"###########################################################################",
"#   >Attack                                   Player- lvl  `   `          #",
"#    Item                                     Health       `   `          #",
"#    Magic                                    Strength     `   `          #",
"#    Flee                                     Evasion      `   `          #",
"###########################################################################",
};

#endif
