#ifndef HOURLY_H
#define HOURLY_H

#include<iostream>
#include "Employee.h"

class Hourly:public Employee{
private:
  double hoursWorked;
public:
  Hourly(float, std::string);
  void addHours(double);
  double pay() override;
  void print() const override;
};
#endif
