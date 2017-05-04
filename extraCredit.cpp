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
#include "characters/player.h"
#include "characters/enemy.h"
using namespace std;


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

void typeLikeUser(string);
void wait(int);
void readFile(string);
void readString(string);
bool checkQuit(string);

/*
Mockups of textfiles that I would have passed to readFile
*/

const string INTRO = "";

int main() {
  string holder; // string for holding things up
  Player me(10);
  try
  {
    readFile("text_assets/intro.txt");
  } catch(int e)
  {
    if (e == 25) {
      readString(INTRO);
    }
  }
  // main game loop
  while(!me.isDead()) {
    // battle loop
    while(me.inBattle) {

    }
    cin >> holder;
  }
  cin >> holder;
  return 0;
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
  const int LOWER_MILLI_RANGE = 25;
  const int UPPER_MILLI_RANGE = 75;
  for(char c : message) {
    int dur = rand() % UPPER_MILLI_RANGE + LOWER_MILLI_RANGE;
    bool longWait = (lastChar == '.');
    bool pauseWait = (lastChar == ',');
    cout << c;
    if (longWait) dur = 750;
    else if (pauseWait) dur = 450;
    wait(dur);
    cout.flush();
    lastChar = c;
  }
}
