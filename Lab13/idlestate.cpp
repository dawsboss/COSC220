#include "idlestate.h"

void IdleState::printOptions(){
    std::cout << "You are sitting facing " << direction << std::endl;

      /* Classic way
      for(int i = 1; i<choices.size() + 1; i++){
        std::cout << i << ". " << choices[i] << std::endl;
      }
      */

      /* More modern way to iterate a std::map */
      for(auto i = choices.begin(); i != choices.end(); i++){
        /*
         * i holds an iterator, which is a pointer to a std::pair<int, string>
         * i->first is the int
         * i->second is the string
         */
        std::cout << i->first << ". " << i->second << std::endl;
      }

}

GameState* IdleState::handleInput(std::string in){
  // cast the string to an int to be interpreted as a choice
  int choice = std::stoi(in);

  // Temp variable to hold the new game state
  GameState* rtn;

  switch (choice){
    case CONTINUE_OPTION:
      std::cout << "\nYou continue sitting...\n";
      rtn = new IdleState(direction);
      break;
    case LEAVE_OPTION:
      std::cout << "\nYou get up, IdIoT...\n";
      rtn = new TravelState(direction);
      break;
    default:
      std::cout << "Invalid option.\n";
      rtn = this;
      break;
  };

  return rtn;

}
