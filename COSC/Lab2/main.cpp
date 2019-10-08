#include <iostream>
#include "PayRoll.h"
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    
  PayRoll employees[7];
  string employeeNames[]={"Grant", "Brock", "Ian", "Ned", "Bob", "Jennifer", "John"};
  float employeePay[]={1000, 10, 12, 15, 17, 16, 22};
  for(int i=0;i<7;i++){//puts my pre set arrays into the objs
    employees[i].setName(employeeNames[i]);
    employees[i].setPay(employeePay[i]);
  }
  PayRoll *dyEmployees[7];
  for(int i=0;i<7;i++)
  {
      dyEmployees[i]=new PayRoll();
  }
  for(int i=0;i<7;i++){//puts my pre set arrays into the objs
    dyEmployees[i]->setName(employeeNames[i]);
    dyEmployees[i]->setPay(employeePay[i]);
  }
  
  
  float holder;//holds the data that will go into employees[i].setWork(
  for(int i=0;i<7;i++)
  {//Gets the hours worked input for all the PayRoll objs
    do
    {//Keeps rerunning until the user inputs something less that 60
      cout<<"How many hours did "<<employees[i].getName()<<" work: "<<endl;
      cin>>holder;
      if(holder>60){
	cout<<"The hours worked cannot exceed 60"<<endl;
      }else if(holder<0){
	cout<<"The hours cannot be negative"<<endl;
      }
    }
    while(holder>60||holder<0);
    employees[i].setWorkTime(holder);
  }
  for(int i=0;i<7;i++){
   cout<<employees[i].getName()<<"'s pay is: $";
   printf("%.2f\n", employees[i].totalPay());
  }
  
  
  cout<<"Now let's try this dynamically"<<endl;
  
  
  
  for(int i=0;i<7;i++){//Gets the hours worked input for all the PayRoll objs
    do{//Keeps rerunning until the user inputs something less that 60
      cout<<"How many hours did "<<dyEmployees[i]->getName()<<" work: "<<endl;
      cin>>holder;
      if(holder>60)
      {cout<<"The hours worked cannot exceed 60"<<endl;
      }else if(holder<0)
      {
	cout<<"You cannot have a negative time works."<<endl;
      }
    }while(holder>60 || holder<0);
    dyEmployees[i]->setWorkTime(holder);
  }
  for(int i=0;i<7;i++){
   cout<<dyEmployees[i]->getName()<<"'s pay is: $";
   printf("%.2f\n", dyEmployees[i]->totalPay());
  }
  
  cout<<endl;
  cout<<"side testing fro numbers 9 and 10"<<endl;
  cout<<"non dynamic size: "<<sizeof(employees)<<endl;
  cout<<"dynamic size: "<<sizeof(dyEmployees)<<endl;
  
  for(int i=0;i<14;i++)
  {
    if(i<7)
    {
      cout<<"Adress of \"static\": "<<employees[i].getName()<<" :: "<<&employees[i]<<endl;
    }else if(i>=7)
    {
      cout<<"Adress of dynamic;: "<<dyEmployees[i-7]->getName()<<" :: "<<&dyEmployees[i-7]<<endl;
    }
      
  }
  
  for(int i=0;i<7;i++)
  {
     delete dyEmployees[i];    
  }
}



/* Number 9:
/* 	The dynamic array was 56 bits and the non-dynamic array of PayRoll was 112 bits
 * 	The dynamic array was less data and was 8 bytes per obj/ptr because we are running
 *		 on a 64 bit system so each adress is 64 bits/8bytes
 * 	
 * 	The "static" array was 112 bits for the whole array. This is because 112-56 is 56
 *		We subtract 56 from the 112 because that is the memory stored to access the objs 
 * 		The second 56 is from the actual memory that the objects are holding. 
 * 
 * 	We see a diffrence becuase the dynamics data/onjs are stored in the heap and the "static"
 *		 is in the stack
 * Number 10: 
 * 	The "static" aray is stored ever 16 decimals, so each index gets 2 bytes / 16 bits
 * 
 * 	The dynamic is increasing by 8 decimal, so each index is 1 byte / 8 bits
 * 
 * 	Which this makes sence because the size of the "static" was x2 the size of the dynamic
 * 
 */
