//Grant dawson COSC 220 Project 1
#include "Student.h"

using namespace std;

Student::Student(){
  name="Not Entered";
  DOB="Not Entered";
  major="Not Entered";
}

Student::Student(string n, string d, string m){
  name=n;
  DOB=d;
  major=m;
}

//this will return wheather or not two students are equivlenent in the fac tof thier data
bool Student::operator ==(Student sTwo){
  if(name==sTwo.getName() && DOB==sTwo.getDOB() && major==sTwo.getMajor()){
    return true;
  }
  return false;
}

void Student::print(){
  cout<<"Name: "<<name<<" | Date of Birth: "<<DOB<<" | Major: "<<major<<endl;
}

string Student::getName(){
  return name;
}
string Student::getDOB(){
  return DOB;
}
string Student::getMajor(){
  return major;
}

void Student::setName(string n){
  name=n;
}
void Student::setDOB(string d){
  DOB=d;
}
void Student::setMajor(string m){
  major=m;
}
