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

int main() {
  string holder; // string for holding things up
  string testMessage = "Hello John!  I am learning to type things out!\nIsn't that the coolest thing that you've ever seen?!\nNo, you're right, probably not.  But you knwo what?  I don't care!\nThis shit is gonna get me an A!!";
  typeLikeUser(testMessage);
  Player me(10);
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
  for(char c : message) {
    int dur = rand() % 100;
    bool longWait = (c == '\n');
    cout << c;
    if (longWait) dur = 750;
    wait(dur);
    cout.flush();
  }
}
