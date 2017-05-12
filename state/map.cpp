#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "map.h"
#include "map_schemas.h"
#include "../characters/actor.h"
#include "../characters/player.h"
#include "../items/item.h"
#include "../items/equipable_item.h"
#include "../items/usable_item.h"
#include "../containers/container.h"
#include "../containers/chest.h"
#include "../containers/bagofholding.h"
using namespace std;

Map::Map() {
}
void Map::render( int playerDepth, vector<Actor*> &actorptrs ) {
  /*
  like most things, render draws out the map, which is has (0,0) at the
  upper left hand corner.  The list of actorptrs contains player as well
  player actor should always be in position 0
  */
  static int from = 0;
  static bool left = 0;
  static bool right = 0;

  Actor *player = actorptrs[0];

  string* schema;
  int schemaLength;
  switch(playerDepth) {
    case 0: {
      cout << DEPTH_0_ROOM_NAME << endl;
      schema = DEPTH_0;
      schemaLength = DEPTH_0_LENGTH;
      if (from == 1) {
        cout << "attempting to exit the cave\n";
        player->setXPos(DEPTH_0_NORTHERN_X);
        player->setYPos(DEPTH_0_NORTHERN_Y);
        player->setPrevX(DEPTH_0_NORTHERN_X);
        player->setPrevY(DEPTH_0_NORTHERN_Y);
      }
      from = 0;
      break;
    }
    case 1:{
      cout << DEPTH_1_ROOM_NAME << endl;
      schema = DEPTH_1;
      schemaLength = DEPTH_1_LENGTH;
      if (from == 0) {
        player->setXPos(DEPTH_1_SOUTHERN_X);
        player->setYPos(DEPTH_1_SOUTHERN_Y);
        player->setPrevX(DEPTH_1_SOUTHERN_X);
        player->setPrevY(DEPTH_1_SOUTHERN_Y);
      } else if (from == 2) {
        player->setXPos(DEPTH_1_NORTHERN_X);
        player->setYPos(DEPTH_1_NORTHERN_Y);
        player->setPrevX(DEPTH_1_NORTHERN_X);
        player->setPrevY(DEPTH_1_NORTHERN_Y);
      }
      from = 1;
      break;
    }
    case 2: {
      cout << DEPTH_2_ROOM_NAME << endl;
      schema = DEPTH_2;
      schemaLength = DEPTH_2_LENGTH;
      if (from == 1) {
        player->setXPos(DEPTH_2_SOUTHERN_X);
        player->setYPos(DEPTH_2_SOUTHERN_Y);
        player->setPrevX(DEPTH_2_SOUTHERN_X);
        player->setPrevY(DEPTH_2_SOUTHERN_Y);
      } else if (from == 3 && left) {
        player->setXPos(DEPTH_2_NORTHERN_X_L);
        player->setYPos(DEPTH_2_NORTHERN_Y_L);
        player->setPrevX(DEPTH_2_NORTHERN_X_L);
        player->setPrevY(DEPTH_2_NORTHERN_Y_L);
      } else if (from == 3 && right){
        player->setXPos(DEPTH_2_NORTHERN_X_R);
        player->setYPos(DEPTH_2_NORTHERN_Y_R);
        player->setPrevX(DEPTH_2_NORTHERN_X_R);
        player->setPrevY(DEPTH_2_NORTHERN_Y_R);
      }
      from = 2;
      break;
    }
    case 3: {
      if(from == 2){
        left = (player->getXPos() < DEPTH_2_EXIT_L);
        right  = (player->getXPos() > DEPTH_2_EXIT_R);
      }
      if (left) {
        cout << DEPTH_3_ROOM_NAME_L << endl;
        schema = DEPTH_3_L;
        schemaLength = DEPTH_3_LENGTH_L;
        if(from == 2){
          player->setXPos(DEPTH_3_SOUTHERN_X_L);
          player->setYPos(DEPTH_3_SOUTHERN_Y_L);
          player->setPrevX(DEPTH_3_SOUTHERN_X_L);
          player->setPrevY(DEPTH_3_SOUTHERN_Y_L);
        }
      } else if (right) {
        cout << DEPTH_3_ROOM_NAME_R << endl;
        schema = DEPTH_3_R;
        schemaLength = DEPTH_3_LENGTH_R;
        if(from == 2){
          player->setXPos(DEPTH_3_SOUTHERN_X_R);
          player->setYPos(DEPTH_3_SOUTHERN_Y_R);
          player->setPrevX(DEPTH_3_SOUTHERN_X_R);
          player->setPrevY(DEPTH_3_SOUTHERN_Y_R);
        } else if (from == 4) {
          player->setXPos(DEPTH_3_NORTHERN_X_R);
          player->setYPos(DEPTH_3_NORTHERN_Y_R);
          player->setPrevX(DEPTH_3_NORTHERN_X_R);
          player->setPrevY(DEPTH_3_NORTHERN_Y_R);
        }
      }
      from = 3;
      break;
    }
    case 4: {
      cout << DEPTH_4_ROOM_NAME << endl;
      schema = DEPTH_4;
      schemaLength = DEPTH_4_LENGTH;
      if (from == 3) {
        player->setXPos(DEPTH_4_SOUTHERN_X);
        player->setYPos(DEPTH_4_SOUTHERN_Y);
        player->setPrevX(DEPTH_4_SOUTHERN_X);
        player->setPrevY(DEPTH_4_SOUTHERN_Y);
      }
      from = 0;
      break;
    }
    default:
      cout << "K, so, how'd you pull this off?\n";
      cout << "You broke my game :'(\n";
      break;
  }
  cout << "entering check loop\n";
  for(int i = 0; i < schemaLength; i++) {
    /*
    I should call this out as a function that takes in the positions of
    all of the members of the actorVector so that I don't have to do
    multiple loops to check in the render function itself.

    for the sake of this, consider i to be the row number or y
    of the player/enemy classes
    this loop will render the charcters to the screen as P, or E,
    and handles collision with the walls which are '*' characters.
    */
    // pre-render row of the actor
    string &row = schema[i];
    // row for actors colliding south bound
    string &rowAbove = schema[i - 1];
    // row for actors colliding northbound
    string &rowBelow = schema[i + 1];
    // loop check for relevant actors, if none skip collision testing etc
    for (int j = 0; j < actorptrs.size(); j++) {
      Actor *curActor = actorptrs[j];
      if (!(curActor->getYPos() == i)) {
        // actor isn't in row and isn't relevant to render
        continue;
      }
      else {
        // 0 index is player
        string repr = !j ? "P" : "E";
        int priorX = curActor->getXPos();
        int priorY = curActor->getYPos();
        // wall collision corrects actor position in the case of a collision
        // if a wall collision occurs we want to skip killing the ghost
        // this makes the mechanics of enemy collision more stable
        // read: approach from behind is possible when player is against a
        // wallCollision returns false for collision occured
        bool shouldClear = wallCollision(curActor, row);
        int correctedX = curActor->getXPos();
        int correctedY = curActor->getYPos();
        // if true, position was allowed to stay changed in wallCollision

        if(shouldClear) {// true when there isn't a collision
          // insert actor character into current row string
          row.replace(row.begin() + (correctedX - 1), row.begin() + correctedX, repr);
          // clear ghosts based on direction of travel
          int direction = curActor->getDirection();
          switch (direction) {
            case 1: // northbound
              rowBelow.replace(rowBelow.begin() + (curActor->getXPos() - 1), rowBelow.begin() + curActor->getXPos(), " ");
              break;
            case 2: // eastbound (and down!  loaded up and truckin')
              row.replace(row.begin() + (curActor->getPrevX() - 1), row.begin() + curActor->getPrevX(), " ");
              break;
            case 3: // southbound
              // trailing actor is caused by rowAbove being rendered prior to the removal of the actor character.
              rowAbove.replace(rowAbove.begin() + (curActor->getXPos() - 1), rowAbove.begin() + curActor->getXPos(), " ");
              break;
            case 4: // westbound
              row.replace(row.begin() + (curActor->getPrevX() - 1), row.begin() + curActor->getPrevX(), " ");
              break;
            default:
              // gets hit for any actor that isn't moving
              break;
          }
        } else {
          if (curActor->getDirection() == 1){
            // northbound render correct for collision
            rowBelow.replace(rowBelow.begin() + (correctedX - 1), rowBelow.begin() + correctedX, repr);
          }
          else if (curActor->getDirection() == 3) {
            // southbound render correct for collision
            rowAbove.replace(rowAbove.begin() + (correctedX - 1), rowAbove.begin() + correctedX, repr);
          }
        }
      }
    }
  }
  // this isn't thaaat much more expensive... :P
  for(int i = 0; i < schemaLength; i++) {
    cout << schema[i] << endl;
  }
}

void renderBattle(/*Player and enemy instances*/) {
  /*
  Takes the player and enemy instances involved in a kerfuffle and uses their
  stats to output the visualiztion of the battle menu.
  */
  enum Options { attack = 1, item, magic, flee };

}

void Map::clear(string system_command, bool pause_for_enter) {
  if (pause_for_enter) {
    string holder;
    cin.ignore();
    getline(cin,holder);
  }
  system(system_command.c_str());
}

bool Map::wallCollision(Actor *a, string row) {
  /*
  handles actor colliding with wall char '*'
  */
  enum Cardinal { north = 1, east, south, west };
  int direction = a->getDirection();
  char newPos = row.at(a->getXPos() - 1);
  if (!(newPos == ' ')) {
    switch (direction) {
      case north:{
        // player x remains unchanged, but y needs to be set to prev
        // prev needs to be set + 1 since direction of implies subtraction
        a->setYPos(a->getPrevY());
        a->setPrevY(a->getPrevY() + 1);
        return 0;
      }
      case east:{
        // player x has shifted up, so reset x to prev and prev to -1
        a->setXPos(a->getPrevX());
        a->setPrevX(a->getPrevX() - 1);
        return 0;
      }
      case south:{
        a->setYPos(a->getPrevY());
        a->setPrevY(a->getPrevY() - 1);
        return 0;
      }
      case west:{
        a->setXPos(a->getPrevX());
        a->setPrevX(a->getPrevX() + 1);
        return 0;
      }
      default:
        break;
    }
  }
  return 1;
}
