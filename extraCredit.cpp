/*
Program Name: Cave Diver
Program Description: Simple text based RPG game where the goal is to slay the
                     dragon at the bottom of the cave.  No one ever accused me
                     of being creative...

*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <fstream>
#include "player.h"
#include "enemy.h"
using namespace std;


unordered_map<std::string, std::string>  DESCRIPTIONS = {
  {"Goblin", "Grotesque creatures known to frequent caves and dark, moist places.\n"},
  {"Bear", ""},
  {"Hob-Goblin", ""},
  {"Demon", ""},
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

void readFile(string filePath) {
  string line;
  ifstream introFile(filePath);
  if(introFile.is_open()) {
    while(getline(introFile, line)) {
      typeLikeUser(line);
      cout << endl;
    }
    introFile.close();
  }
  else cout << "unable to open file\n";
}

int main() {
  string holder; // string for holding things up
  Player me(10);
  readFile("text_assets/intro.txt");
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
