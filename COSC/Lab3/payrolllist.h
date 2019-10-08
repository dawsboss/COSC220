//Grant Dawson COSC 220

#ifndef PAYROLLLIST_H
#define PAYROLLLIST_H

#include <iostream>
#include "PayRoll.h"

using namespace std;

class PayRollList{
  private:
    struct ListNode {
	PayRoll p;
	ListNode* next;
    };
    
    ListNode* head;
  public:
    PayRollList();
    ~PayRollList();
    
    void insert(string, float, float);//inserts a newly created obj 
    void insert(PayRoll);//inserts a whole obj
    void printPayChecks();//prints linked list
};

#endif
