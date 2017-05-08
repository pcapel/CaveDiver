/*
Program Name: Cave Diver
Program Description: Simple text based RPG game where the goal is to slay the
                     dragon at the bottom of the cave.  No one ever accused me
                     of being creative...
Author: Philip Capel
Date: Sometime between the beginning of May and whenever you're reading this
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "characters/player.h"
#include "characters/enemy.h"
#include "state/map.h"
using namespace std;

const string CLEAR_COMMAND = "clear";
const bool SPEED_OVERRIDE = false;

unordered_map<std::string, std::string>  DESCRIPTIONS = {
  {"Goblin", "Grotesque creatures known to frequent caves and dark, moist places.\n"},
  {"Bear", "Burly beasts with claws sharpened by their lumbering motion. They hunger for flesh.\n"},
  {"Hob-Goblin", "A larger, meaner, and somehow smellier version of the Goblin.\n"},
  {"Demon", "Fearsome demi-gods from the depths of the Earth. Their rage against humanity burns like the Sun."},
  {"Behemaht", "The Dragon of the Depths.  Behemaht is the evil that feeds the cavern and attracts the creatures within."},
};

unordered_map<std::string, std::string>  MESSAGES = {
  {"attacked", "You are being attacked by a "},
  {"encountered", "You have encountered a "},
  {"killed", "You have been killed by a "},
  {"found", "You have found a "},
  {"rest", "You have rested, and feel considerably better!"},
};

const int NON_BATTLE_MENU_SIZE = 6;
const string NON_BATTLE_MENU[] = {
  "Move Forward, deeper into the cave.",
  "Move backwards, away from your goal, and to safety.",
  "Take the path to your right.",
  "Take the path to your left.",
  "Rest your bones for a moment.",
  "Quit your quest.",
};

void typeLikeUser(string);
void wait(int);
void readFile(string);
void readString(string);
bool checkQuit(string);

void playIntro();
void printMenu(const string*, int);

/*
Mockups of textfiles that I would have passed to readFile
*/

const string INTRO = "";

int main(int argc, char *argv[], char *envp[]) {
  string holder; // string for holding things up
  char userAction; // get you some actions
  // from Actor class
  // xpos, ypos, level, health, strength, evasion, attack_type, evasion_fraction
  // player specific
  // depth
  // xpos for depth 0 = 49
  // ypos for depth 0 = 13
  Player Me(49,13,1,10,10,4,1,0.13,0);
  vector<Actor*> actorVector;
  actorVector.push_back(&Me);
  Map cavern;
  cavern.clear(CLEAR_COMMAND);
  cout << "For the best gameplay experience\n"
            "please be sure to set your viewport\n"
             "to at least 80 Columns by 40 Lines.\n"
             "Enjoy!\n"
             "Phil\n\n\n"
             "Enter to continue...";
  cin.ignore();
  getline(cin,holder);
  cavern.clear(CLEAR_COMMAND);
  playIntro();
  // main game loop
  while(!Me.isDead()) {
    cout << Me.getXPos() << " " << Me.getYPos() << endl;
    // instantiation of enemies dependant on the current level of the player
    switch (Me.getDepth()) {
      // instantiation call signature for enemies type
      // from Actor class
      // xpos, ypos, level, health, strength, evasion, attack_type, evasion_fraction
      // enemy specific
      // name, description, attack_type(not supported)
      case 0: // beginning of game, no enemies
        for (int m = 1; m < actorVector.size(); m++) {
          actorVector.erase(actorVector.begin() + m);
        }
        break;
      case 1: {
        for (int m = 1; m < actorVector.size(); m++) {
          actorVector.erase(actorVector.begin() + m);
        }
        Enemy currentEnemy(40,5,1,4,2,2,1,0.1, "Goob", "A goober"); // test enemy
        actorVector.push_back(&currentEnemy);
        break;
      }
      case 2:
        for (int m = 1; m < actorVector.size(); m++) {
          actorVector.erase(actorVector.begin() + m);
        }

        //fill
        break;
      case 3:
        for (int m = 1; m < actorVector.size(); m++) {
          actorVector.erase(actorVector.begin() + m);
        }
        //fill
        break;
      case 4:
        for (int m = 1; m < actorVector.size(); m++) {
          actorVector.erase(actorVector.begin() + m);
        }
        //boss
        break;
      default:
        cout << "How on earth did you get this?\n";
        cout << "You've found a bug.  Please email me.\n";
        break;
      }

    cavern.render(Me.getDepth(), actorVector);
    cin >> userAction;

    Me.move(userAction);

    // // set up random movement
    // srand(time(NULL));
    // // test for enemies
    // for (int i = 1; i < actorVector.size(); i++) {
    //   Actor *e = actorVector[i];
    //   char moves[] = {'w','a','s','d'};
    //   char randMove = moves[(rand() % 4)];
    //   e->move(randMove);
    // }

    // battle check
    int battleIndex = 1;
    for (;battleIndex < actorVector.size(); battleIndex++) {
      if (Me.getXPos() == actorVector[battleIndex]->getXPos()
          && Me.getYPos() == actorVector[battleIndex]->getYPos())
          Me.toggleInBattle();
    }
    // battle loop
    while(Me.battleStatus() == true) {
      string holldup;
      cout << "YOU'RE IN BATTTERLLLLL!!!!\n";
      cin >> holldup;
      // Menu battleMenu(Me, actorVector[battleIndex]);
    }
    cavern.clear(CLEAR_COMMAND);
  }
  cin >> holder;
  return 0;
}

void printMenu(const string *menu, int menuSize) {
  cout << "Current action choices are:\n";
  for(int i = 0; i < menuSize; i++) {
    cout << i << ": " << menu[i] << endl;
  }
}

void playIntro() {
  char uin;
  string cont;
  system(CLEAR_COMMAND.c_str());
  cout << "Would you like to skip the intro y or n?\n>";
  cin >> uin;
  system(CLEAR_COMMAND.c_str());
  while(!(uin == 'y') && !(uin == 'n')) {
    cout << "You must enter y or n\n>";
    cin >> uin;
    system(CLEAR_COMMAND.c_str());
  }
  if(uin == 'n') {
    try
    {
      readFile("text_assets/intro.txt");
    } catch(int e)
    {
      if (e == 25) {
        readString(INTRO);
      }
    }
    cout << "\nEnter to continue...\n";
    cin.ignore();
    getline(cin,cont);
    system(CLEAR_COMMAND.c_str());
  }
}

/*
reads out a file using the typeLikeUser function
or throws error 25 if file not found/can't be opened
*/
void readFile(string filePath) {
  string line;
  ifstream introFile(filePath);
  if(introFile.is_open()) {
    while(getline(introFile, line)) {
      typeLikeUser(line);
      cout << endl;
    }
    introFile.close();
  } else throw 25;
}

void readString(string content) {
    typeLikeUser(content);
    cout << endl;
}


void wait(int duration) {
  chrono::milliseconds dura(duration);
  this_thread::sleep_for(dura);
}

void typeLikeUser(string message) {
  /*
  cout to stdio in a janky, typing way, like someone is inputing info
  requires trailing whitespace on line ends to pause correctly
  */
  char lastChar;
    const int LOWER_MILLI_RANGE = SPEED_OVERRIDE ? 1 : 25;
    const int UPPER_MILLI_RANGE = SPEED_OVERRIDE ? 1 : 75;
    for(char c : message) {
      int dur = rand() % UPPER_MILLI_RANGE + LOWER_MILLI_RANGE;
      bool longWait = (lastChar == '.');
      bool pauseWait = (lastChar == ',');
      cout << c;
      if (longWait) dur = SPEED_OVERRIDE ? 1 : 750;
      else if (pauseWait) dur = SPEED_OVERRIDE ? 1 : 450;
      wait(dur);
      cout.flush();
      lastChar = c;
  }
}
