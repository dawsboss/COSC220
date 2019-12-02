//Grant dawson COSC 220 Project 2
#ifndef HANOISTACK_H
#define HANOISTACK_H

#include <iostream>
#include "HanoiDisc.h"

using namespace std;

class HanoiStack{
private:
  struct DiscNode{
    HanoiDisc d;
    DiscNode* next;
  };
  DiscNode* head;
public:
  HanoiStack();
  HanoiStack(int);
  ~HanoiStack();
  HanoiStack(const HanoiStack&);
  HanoiStack* operator=(const HanoiStack&);
  bool operator==(const HanoiStack&);
  void operator+=(HanoiDisc&);
   // void operator << (const HanoiStack &c);

  void push(HanoiDisc);
  HanoiDisc pop();
  int size() const;
  int peak();

  void print();

};

#endif
