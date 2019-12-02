//Grant Dawson COSC 220 Project 2
#include "HanoiDisc.h"

using namespace std;


  HanoiDisc::HanoiDisc(){
    size=0;
  }
  HanoiDisc::HanoiDisc(int s){
    size=s;
  }
  //bool HanoiDisc::operator +=(HanoiDisc){

  //}
  void HanoiDisc::setSize(int s){
    size=s;
  }
  int HanoiDisc::getSize() const{
    return size;
  }
//compares two disk's sizes to one another.
  bool HanoiDisc::operator ==(HanoiDisc& RHS){
    if(size==RHS.getSize()){
      return true;
    }
    return false;
  }
