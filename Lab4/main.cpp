//Grant Dawson COSC 220
#include <iostream>
#include "PayRoll.h"
#include "payrolllist.h"
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

int main(){
  PayRollList* payChecks = new PayRollList;
  string employeeNames[7];
  float employeePay[7];
  float employeeHours[7];


  ifstream input ("inputs.txt");
  int i=0;
  while(!input.eof()){
    if(i<7){
    input>>employeeNames[i];
    input>>employeePay[i];
    input>>employeeHours[i];
    }else{
      string name;
      input>>name;
      float payment;
      input>>payment;
      float workTime;
      input>>workTime;
      PayRoll temp(payment, workTime, name);
      payChecks->insert(temp);
    }
    i++;
  }
  input.close();

  PayRoll employees[7];
  for(int i=0;i<7;i++){
    employees[i].setName(employeeNames[i]);
    employees[i].setPay(employeePay[i]);
    employees[i].setWorkTime(employeeHours[i]);
  }
  for(int i=0;i<7;i++){
   payChecks->insert(employees[i]);
  }

  char YorN;
  string name;
  float pay;
  float hours;

  bool repeat;
  do{
    cout<<"Would you like to add anyother person to the payroll? y or n"<<endl;
    cin>>YorN;

    if(YorN=='y'){
	repeat =  true;
	  cout<<"What is their name: "<<endl;
	  cin>>name;
	  cout<<"How many hours did they work: "<<endl;
	  cin>>hours;
	  cout<<"What is their hourly pay: "<<endl;
	  cin>>pay;
	  payChecks->insert(name, pay, hours);
    }else if(YorN=='n'){
      repeat = false;
      //Implementation of Lab4

      cout<<"The length of the list is: "<<payChecks->length()<<endl;//int length();

      PayRoll x(45.98, 25, "JACK");
      payChecks->insert(1,x);//void insert(int, PayRoll);
      payChecks->insert(0,x);
      cout<<endl;
      payChecks->printPayChecks();
      payChecks->remove(-1);//void remove(int);
      payChecks->remove(0);
      cout<<endl;
      payChecks->printPayChecks();
      payChecks->assign(5, x);//void assign(int, PayRoll);
      cout<<endl;
      PayRoll* holder = (*payChecks)[0]; //PayRoll* operator[](int);
      cout<<holder->getName()<<" was header of the list and paid the least!"<<endl;
      cout<<endl;



      PayRollList* payChecks2 = new PayRollList(*payChecks);
      payChecks2->printPayChecks();//To show the copy contructor works
      cout<<endl;
      payChecks->printPayChecks();
      //delete payChecks2;
    }else{
      repeat=true;
      cout<<"Please input a y for yes or a n for no"<<endl;
    }
  }while(repeat);
  delete payChecks;
}
