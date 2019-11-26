#ifndef COMBATSTATE_H
#define COMBATSTATE_H

#include <iostream>
#include "gamestate.h"
#include "travelstate.h"
#include <stdlib.h>
#include <time.h>

class CombatState: public GameState {
  private:
    enum Choices {
      CONTINUE_OPTION = 1,
      LEAVE_OPTION    = 2
    };
    std::string direction;
    int Monhealth;
    int HumDamage;
  public:
    CombatState(std::string dir){
      direction = dir;

      choices[CONTINUE_OPTION] = "Fight.";
      choices[LEAVE_OPTION] = "Run away, iDiOt";
    };

    CombatState(std::string dir, int MHealth, int HDamage){
      Monhealth=Monhealth;
      HumDamage=HDamage;
      direction=dir;

      choices[CONTINUE_OPTION] = "Fight.";
      choices[LEAVE_OPTION] = "Run away, iDiOt";
    };

    void printOptions() override;

    GameState* handleInput(std::string) override;


};

#endif
