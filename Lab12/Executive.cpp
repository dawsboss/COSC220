// Executive(double,std::string);
// void setBonus(double);
// double pay();
// void print();
#include"Executive.h"
//constructor gives the requested data to the base class and inizializes the new data
Executive::Executive(std::string n, double p):Employee(n,p){
  bonus=0;
}
//This is not overriden because it is not native to the base class and is nonaccecable from the Employee
void Executive::setBonus(double b){
  bonus=b;
}
//This is a version of the pay function from base class Employee being overloaded

double Executive::pay(){
  double Bonus=bonus;
  bonus=0;
  return payRate+Bonus;
}
//This is a version of the print function from base class Employee being overloaded
void Executive::print() const{
      std::cout<<"Name:"<<name<<" payRate:"<<payRate<<" Bonus:"<<bonus<<std::endl;
}
