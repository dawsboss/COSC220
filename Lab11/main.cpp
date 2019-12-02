#include <iostream>
#include "MyStack.h"
#include "PayRoll.h"
#include <fstream>

int main(){
  MyStack<int> oof;
  oof.push(5);
  int x = oof.pop();
  std::cout<<x<<std::endl;
  cout<<endl;
  MyStack<string> foo;
  foo.push("Grant");
  foo.push("Zak");
  string y = foo.pop();
  std::cout<<y<<std::endl;
  y=foo.pop();
  std::cout<<y<<std::endl;
  cout<<endl;
  MyStack<PayRoll> PR1;
  //PayRoll(float pay, float hours, string name);

  ifstream input ("inputs.txt");
  while(!input.eof()){
      string name;
      input>>name;
      float payment;
      input>>payment;
      float workTime;
      input>>workTime;
      PayRoll temp(payment, workTime, name);
      PR1.push(temp);
  }
  PR1.print();
  input.close();
  PayRoll printer;
  printer = PR1.peak();
  cout<<endl;
  cout<<"This was peeked: "<<endl;
  printer.printInfo();

  cout<<endl;
  cout<<"My the popping begin: "<<endl;
  int size=PR1.size();
  for(int i=0;i<size;i++){
    printer=PR1.pop();
    printer.printInfo();
  }


  return 0;
}
