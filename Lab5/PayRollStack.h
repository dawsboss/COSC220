//Grant Dawson COSC 220
#include "PayRoll.h"
#include <iostream>

#ifndef PAYROLLSTACK_H
#define PAYROLLSTACK_H

class PayRollStack{
  private:
    struct StackNode {
    PayRoll p;
    StackNode* next;
    };
    StackNode* head;
  public:
    PayRollStack();
    ~PayRollStack();
    PayRollStack(const PayRollStack&);
    PayRollStack* operator=(const PayRollStack&);
    // Adds a PayRoll object into the stack
    void push(PayRoll p);
    // Returns the payroll object that was most recently pushed
    PayRoll pop();
    // Alternative, but common, method:
    // instead of using a return, take the destination container
    // as a parameter to the pop function
    void pop(PayRoll&);
    // Returns the number of elements on the stack
    int size();
};

#endif
