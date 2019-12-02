#include <iostream>
#include "PayRoll.h"
#include "payrolllist.h"
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

int main(){
  PayRollList* payChecks = new PayRollList;
  string employeeNames[7];//to hold the values from rading the file.
  float employeePay[7];
  float employeeHours[7];
  
   
  ifstream input ("inputs.txt");
  int i=0;
  while(!input.eof()){//reading in the inputs from a file and maiing an array of each type.
    input>>employeeNames[i];
    input>>employeePay[i];
    input>>employeeHours[i];
    i++;
  }
  input.close();
  
  PayRoll employees[7];
  for(int i=0;i<7;i++){//puts my pre set arrays into the objs
    employees[i].setName(employeeNames[i]);
    employees[i].setPay(employeePay[i]);
    employees[i].setWorkTime(employeeHours[i]);
  }
  for(int i=0;i<7;i++){
   payChecks->insert(employees[i]);//puts the file objs into the list.
  }
  
  char YorN;//to see if the user wants to say yes or no
  string name;
  float pay;
  float hours;
  
  bool repeat;//if we need to repeat the loop or no? add another or input the whrong thing.
  do{//allows for user input and the use of insert(float,flaot,string)
    cout<<"Would you like to add anyother person to the payroll? y or n"<<endl;
    cin>>YorN;
    
    if(YorN=='y'){//if the want to add someone give them the code to do so
	repeat =  true;//Tests the second portions of the insert functions and leaves room for easy adding out of the text file
	  cout<<"What is their name: "<<endl;
	  cin>>name;
	  cout<<"How many hours did they work: "<<endl;
	  cin>>hours;
	  cout<<"What is their hourly pay: "<<endl;
	  cin>>pay;
	  payChecks->insert(name, pay, hours);
    }else if(YorN=='n'){//if they don't print the checks
      repeat = false;
      payChecks->printPayChecks();

    }else{//if they give something that y or n
      repeat=true;
      cout<<"Please input a y for yes or a n for no"<<endl;
    }
  }while(repeat);
  delete payChecks;//deletes the list once done
}
