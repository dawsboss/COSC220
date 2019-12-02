//Grant Dawson COSC 220 Project 2
#include "HanoiDisc.h"
#include "HanoiStack.h"
#include <stdlib.h>



void solveHanoi(int n, int start, int end, int tmp){
  if(n>=1){
    solveHanoi(n-1, start, tmp, end);
    cout<<"Move Disc "<<n<<" from Tower#"<<start<<" to Tower#"<<end<<endl;
    solveHanoi(n-1, tmp, end, start);
  }
}



int main(int argc, char** arg){
  int counter=0;
  if(argc<1){
    cout<<"Incorrect arguments : ./main n\n\t n - Height of the first stack(2-10)"<<endl;
    return 69;
  }
  if(argc<2||atoi(arg[1])>10||atoi(arg[1])<2){
    cout<<"Incorrect arguments : ./main n\n\t n - Height of the first stack(2-10)"<<endl;
    return 1;
  }
  HanoiDisc x;
  HanoiDisc fail(-69);
  HanoiStack Holder1(atoi(arg[1]));
  HanoiStack win(atoi(arg[1]));
  HanoiStack Holder2;
  HanoiStack Holder3;
  //don't call any holdrs
  HanoiStack Stacks[3]={Holder1, Holder2, Holder3};
  int p;


//This is the loop that loops them putting in what (user)they want to do
  while(true){

    for(int i=0;i<3;i++){
      cout<<"Tower "<<i+1<<": "<<endl;
      Stacks[i].print();
    }
    cout<<"Which tower would you like to take the top from(1-3): "<<endl;
    cout<<"Or if you wamt what the answer would be then input -1"<<endl;
    cin>>p;
    //check for broken cin
    if(cin.fail()){
      cin.clear();
      cin.ignore();
      cout << "Invalid input; please re-enter.\n";
      continue;
    }
    //check if they want the answer
    if(p==-1){
      solveHanoi(atoi(arg[1]),1,2,3);
      continue;
    }
    //where we poping from bois
    //what stack they want the top popped from
    if(p>3||p<1){
        cout<<"Not a valid choice"<<endl;
        continue;
    }
    x=Stacks[p-1].pop();
    //if the popping failed then warn them
    if(x==fail){
      cout<<"Stack is empty"<<endl;
      continue;
    }

    //This will loop until thy pick a valid place to place theur node the popped
    while(true){
        cout<<"Where would you like to place disk: "<<x.getSize()<<endl;
        cin>>p;
	//if cin fails don't break
      if(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Invalid input; please re-enter.\n";
        continue;
      }
      //makes sure it is leagl to push here
      if(x.getSize()>Stacks[p-1].peak()){
        cout<<"Tower #"<<p<<" has a smalled disc than "<<x.getSize()<<" on top!\nCan't place that there."<<endl;
        for(int i=0;i<3;i++){
          cout<<"Tower "<<i+1<<": "<<endl;
          Stacks[i].print();
        }
        continue;
      }else{
	//if it si then p has to be 1-3
        if(p>3||p<1){
          cout<<"Not a valid choice"<<endl;
          continue;
        }
        Stacks[p-1].push(x);
        break;
      }
    }
    //Check if you won
    counter++;
    if(Stacks[1]==win ||Stacks[2]==win){
      break;
    }
  }
  
  for(int i=0;i<3;i++){
    cout<<"Tower "<<i+1<<": "<<endl;
    Stacks[i].print();
  }
  cout<<"You won in #"<<counter<<" number of moves"<<endl;
  cout<<"You won!"<<endl;
  return 0;
}
