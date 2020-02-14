//Grant Dawson COSC 220

#ifndef PAYROLL_H
#define PAYROLL_H

#include <iostream>

using namespace std;

class PayRoll{
  private:
    string name;
    float hrPay;
    float hrWorked;
  public:
    float getPay();
    float getWorkTime();
    string getName();

    void setWorkTime(float newPay);
    void setPay(float newWork);
    void setName(string newName);

    void printInfo();
    float totalPay();

    PayRoll();
    PayRoll(float pay, float hours, string name);
};

#endif
