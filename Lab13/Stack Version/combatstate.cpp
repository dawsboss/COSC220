#include "combatstate.h"

void CombatState::printOptions(){
    std::cout << "Monster HP: ";
    for(int i=0;i<20;i++){
      if(Monhealth>i){
        std::cout<<"#";
      }else{
        std::cout<<"-";
      }
    }
    std::cout<<std::endl;

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

void CombatState::handleInput(std::string in, std::stack<GameState*>& states){

  // cast the string to an int to be interpreted as a choice
  int choice = std::stoi(in);

  switch (choice){
    case CONTINUE_OPTION:

      if((Monhealth-HumDamage)<=0){
        std::cout<<"You killed the monster...\n";
        delete states.top();
        states.pop();
        //rtn=new TravelState(direction);
      }else{
        std::cout << "\nYou continue fighting...\n";
        Monhealth-=HumDamage;
	//states.push(this); // to make sure it gets reused
        //return this;
        //rtn = new CombatState(direction, Monhealth-HumDamage, HumDamage);
      }
      break;
    case LEAVE_OPTION:
      std::cout << "\nYou run away, IdIoT...\n";
      //rtn = new TravelState(direction);

      break;
    default:
      std::cout << "Invalid option.\n";
      break;
  };
}
