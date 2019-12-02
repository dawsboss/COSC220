#include "Employee.h"
//constructor
Employee::Employee(std::string empName, double empRate){
  name=empName;
  payRate = empRate;
}
//This is the base pay that other functions will override off of
double Employee::pay(){
  return payRate;
}
//This is the base print that other functions will override off of
void Employee::print() const{
  std::cout<<"Employee Name:"<<name<<" payRate:"<<payRate<<std::endl;
}
