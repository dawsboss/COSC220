#include <iostream>
#include "PayRoll.h"
#include <stdio.h>
//Grant Dawson COSC 220

using namespace std;

float PayRoll::getPay(){
  return PayRoll::hrPay;
}
float PayRoll::getWorkTime(){
  return PayRoll::hrWorked;
}
string PayRoll::getName(){
  return PayRoll::name;
}

void PayRoll::setPay(float newPay){
  hrPay = newPay;
}
void PayRoll::setWorkTime(float newWork){
  hrWorked = newWork;
}
void PayRoll::setName(string newName){
  name = newName;
}

float PayRoll::totalPay(){
  return hrPay*hrWorked;
}

void PayRoll::printInfo(){
  cout<<"Name: "<<name<<endl;
  cout<<"Hourly pay: "<<hrPay<<endl;
  cout<<"hours worked: "<<hrWorked<<endl;
}

PayRoll::PayRoll(){
  hrPay=10.10;
  name="John Doe";
}

PayRoll::PayRoll(float pay, float hours, string Name){
  name=Name;
  hrPay=pay;
  hrWorked=hours;
}