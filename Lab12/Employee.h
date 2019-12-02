#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee {
protected:
    double payRate;
    std::string name;
public:
    // non-default constructor
    Employee(std::string empName, double empRate);
    // returns the amount the employee should be paid
    virtual double pay();
    // prints to stdout the employee information
    virtual void print() const;
};

#endif
