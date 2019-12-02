//Grant dawson COSC 220 Project 1
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student{
private:
  string name;
  string DOB;
  string major;

public:
  bool operator ==(Student);

  Student();
  Student(string,string,string);
  string getName();
  string getDOB();
  string getMajor();

  void setName(string);
  void setDOB(string);
  void setMajor(string);

  void print();

};

#endif
