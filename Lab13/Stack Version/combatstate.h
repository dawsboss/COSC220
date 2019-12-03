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
    CombatState(){
      //Randomly makes the monsters health
      Monhealth=(rand()%5 + 16);
      //Randomly makes the humans damage output
      HumDamage=(rand()%25 + 1 );

      choices[CONTINUE_OPTION] = "Fight.";
      choices[LEAVE_OPTION] = "Run away, iDiOt";
    };

    void printOptions() override;

    void handleInput(std::string, std::stack<GameState*>&) override;


};

#endif
