#include "travelstate.h"

void TravelState::printOptions() {
  std::cout << "You are walking " << direction << std::endl;
  if (hasCrossroad){
    std::cout << "You see a fork in the road, headed " << newDirection << std::endl;
  }

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
};

TravelState::~TravelState(){
}

void TravelState::handleInput(std::string in, std::stack<GameState*>& states) {
  // cast the string to an int to be interpreted as a choice
  int choice = std::stoi(in);

  switch (choice){
    case CONTINUE_OPTION:
      std::cout << "\nYou continue walking...\n";
      //You could pop nd re push or flip the coin here
      //If you decide to put the coin flip you would to put it
      //each case or at the top of the function but woudl
      //it make sense to?
      delete states.top();
      states.pop();
      states.push(new TravelState(direction));

      //rtn = new TravelState(direction);
      break;
    case SIT_OPTION:
      std::cout<<"\nYou take a seat..."<<std::endl;
      //rtn = new IdleState(direction);
      states.push(new IdleState());
      break;
    case FORK_OPTION:
      std::cout << "\nYou take the fork...";
      //rtn = new TravelState(newDirection);
      delete states.top();
      states.push(new TravelState(newDirection));
      break;
    case MONSTER_OPTION:
      std::cout<<"\nYou fight the monster..."<<std::endl;
      //rtn=new CombatState(newDirection);
      states.push(new CombatState());
      hasMonster=false;
      break;
    default:
      std::cout << "\nInvalid option.\n";
      break;
  };
};
