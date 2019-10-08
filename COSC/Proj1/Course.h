#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Course{
private:
  string name;
  string department;
  string semester;
  char grade;

public:
  Course();
  Course(string, string, string, char);

  bool operator ==(Course);

  void setName(string);
  void setDepartment(string);
  void setSemester(string);
  void setGrade(char);

  string getName();
  string getDepartment();
  string getSemester();
  char getGrade();

};

#endif
