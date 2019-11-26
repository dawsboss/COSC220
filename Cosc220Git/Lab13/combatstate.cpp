#include "idlestate.h"

void CombatState::printOptions(){
    std::cout << "You begin fighting!" << std::endl;

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

GameState* CombatState::handleInput(std::string in){
  //Randomly makes the monsters healtjh
  srand(time(0));
  health=(rand()%25 + 1);
  //Randomly makes the humans damage output
  srand(time(0));
  HumDamage=(rand()%25 + 1 );
  // cast the string to an int to be interpreted as a choice
  int choice = std::stoi(in);

  // Temp variable to hold the new game state
  GameState* rtn;

  switch (choice){
    case CONTINUE_OPTION:
      std::cout << "\nYou continue fighting...\n";
      if((Monhealth-HumDamage)<=0){
        std::cout<"You killed the monster..."<<endl;
        rtn=new TravelState(direction);
      }else{
        rtn = new CombatState(direction, Monhealth, HumDamage);
      }
      break;
    case LEAVE_OPTION:
      std::cout << "\nYou run away, IdIoT...\n";
      rtn = new TravelState(direction);
      break;
    default:
      std::cout << "Invalid option.\n";
      rtn = this;
      break;
  };

  return rtn;

}
