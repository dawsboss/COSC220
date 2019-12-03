#include "idlestate.h"

void IdleState::printOptions(){
    std::cout << "You are sitting"<< std::endl;

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

void IdleState::handleInput(std::string in, std::stack<GameState*>& states){
  // cast the string to an int to be interpreted as a choice
  int choice = std::stoi(in);

  switch (choice){
    case CONTINUE_OPTION:
      std::cout << "\nYou continue sitting...\n";
      break;
    case LEAVE_OPTION:
      std::cout << "\nYou get up, IdIoT...\n";
      delete states.top();
      states.pop();
      break;
    default:
      std::cout << "Invalid option.\n";
      break;
  };
}
