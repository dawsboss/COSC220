#ifndef TRAVELSTATE_H
#define TRAVELSTATE_H

#include "gamestate.h"
#include "idlestate.h"
#include "combatstate.h"
#include <stdlib.h>
#include <time.h>
#include <list>


class TravelState : public GameState {
  private:

    //Denotes if there is a monster
    bool hasMonster;
    // Current direction of travel
    std::string direction;

    // Denotes if there is a fork
    bool hasCrossroad;

    // The direction of the crossroad
    std::string newDirection;

    // Choice constants
    enum Choices{
      CONTINUE_OPTION = 1,
      SIT_OPTION      = 2,
      FORK_OPTION     = 3,
      MONSTER_OPTION  = 4
    };

    ~TravelState();

  public:
    TravelState(std::string dir){
      std::cout<<"Test"<<std::endl;
      direction = dir;

      // Randomly add a fork in the road
      if ( rand()%10 + 1 > 7 ){ // 30% chance of a turn
        hasCrossroad = true;
        std::list<std::string> dirs;
        dirs.push_front("North");
        dirs.push_front("South");
        dirs.push_front("East");
        dirs.push_front("West");

        // Remove the direction we're going
        dirs.remove(direction);

        // Selects a random direction that we're not already traveling
        newDirection = *std::next(dirs.begin(), rand()%dirs.size());
      } else {
        hasCrossroad = false;
      }

      if( rand()%10 + 1 > 9 ){
        hasMonster=true;
      }else{
        hasMonster=false;
      }

      // Set up the choice text for the user
      choices[CONTINUE_OPTION] = "Keep walking.";
      choices[SIT_OPTION] = "Sit and rest.";
      if (hasCrossroad){
        choices[FORK_OPTION] = "Take the " + newDirection + " fork.";
      }
      if(hasMonster){
        choices[MONSTER_OPTION] = "Fight the monster.";
      }
    }

    void printOptions() override;

    void handleInput(std::string, std::stack<GameState*>&) override;

};

#endif
