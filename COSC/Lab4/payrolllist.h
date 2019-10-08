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

    void insert(string, float, float);
    void insert(PayRoll);
    void printPayChecks();

    //New under
    PayRollList(PayRollList&);
    int length();
    PayRoll* operator[](int);
    void remove(int);
    void assign(int, PayRoll);
    void insert(int, PayRoll);

};

#endif
