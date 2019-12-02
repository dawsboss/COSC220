//Grant dawson COSC 220 Project 1
#include "Course.h"

using namespace std;

Course::Course(string n,string d, string s, char g){
  name=n;
  department=d;
  semester=s;
  grade=g;
}
Course::Course(){
  name="N/A";
  department="N/A";
  semester="N/A";
  grade='N';
}

//This will check two Courses to see if they are "equal" in that all their data is the same
bool Course::operator ==(Course lftS){
  if(name==lftS.getName() && department==lftS.getDepartment() && semester==lftS.getSemester() && grade==lftS.getGrade()){
      return true;
  }
  return false;
}

void Course::setName(string n){
  name=n;
}
void Course::setDepartment(string d){
  department=d;
}
void Course::setSemester(string s){
  semester=s;
}
void Course::setGrade(char g){
  grade=g;
}

string Course::getName(){
  return name;
}
string Course::getDepartment(){
  return department;
}
string Course::getSemester(){
  return semester;
}
char Course::getGrade(){
  return grade;
}
