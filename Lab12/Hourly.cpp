#include "Hourly.h"

//Constructor that constructs and employee with given values and horusWorked to 0
Hourly::Hourly(float x, std::string n):Employee(n,x){
  hoursWorked=0;
}
//This will add to the counter of hours worked
void Hourly::addHours(double hours){
  hoursWorked+=hours;
}
//This will caculate what the employee will be paid based off of how many hours they worked.
double Hourly::pay(){
  double holder= hoursWorked*payRate;
  hoursWorked=0;
  return holder;
}
//prints the emplyees nname, patRate, and hours worked
void Hourly::print() const{
    std::cout<<"Name:"<<name<<" payRate:"<<payRate<<" Hours Worked:"<<hoursWorked<<std::endl;
}
