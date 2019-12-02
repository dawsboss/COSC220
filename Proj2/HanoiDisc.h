//Grant Dawson COSC 220 Project 2
#ifndef HANOIDISC_H
#define HANOIDISC_H

#include <iostream>

using namespace std;

class HanoiDisc{
private:
  int size;
public:
  HanoiDisc();
  HanoiDisc(int);
  //bool operator +=(HanoiDisc);
  void setSize(int);
  int getSize() const;

  bool operator ==(HanoiDisc&);
};

#endif
