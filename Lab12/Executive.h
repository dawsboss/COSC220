#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include<iostream>
#include "Employee.h"

class Executive:public Employee{
private:
  double bonus;
public:
  Executive(std::string, double);
  void setBonus(double);
  double pay() override;
  void print() const override;
};
#endif
