#ifndef IDLESTATE_H
#define IDLESTATE_H

#include <iostream>
#include "gamestate.h"
#include "travelstate.h"

/*
 * TODO: For lab:
 * - implement the two override functions of GameState,
        printOptions and handleInput
 * - implement constructor to remember the status
        of the previous travel state
 */

class IdleState: public GameState {
  private:
    enum Choices {
      CONTINUE_OPTION = 1,
      LEAVE_OPTION    = 2
    };
    std::string direction;
  public:
    IdleState(){
      choices[CONTINUE_OPTION] = "Keep Sitting.";
      choices[LEAVE_OPTION] = "Get up, IdIoT.";
    }

    void printOptions() override;

    void handleInput(std::string, std::stack<GameState*>&) override;


};

#endif
