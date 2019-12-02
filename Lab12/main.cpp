#include<iostream>
#include"Employee.h"
#include"Hourly.h"
#include"Executive.h"

int main(){
  Employee* x=new Employee("Grant",10);
  x->print();
  //Normal working
  Hourly* y=new Hourly(10.10,"Brock");
  y->print();
  y->addHours(10);
  y->print();
  y->addHours(10);
  y->print();
  std::cout<<"Brock will be paid: "<<y->pay()<<std::endl;
  y->print();

  Executive* z=new Executive("Jack", 10000);
  z->setBonus(100);
  z->print();
  std::cout<<"Jack will be paid:"<<z->pay()<<std::endl;
  z->print();
//Stuff gets crazy here...
  std::cout<<"+++++Testing with virtual stuffs+++++"<<std::endl;
  Employee* Company1[] = {x,y,z};
  //This without virtual will print the "print" function from Employee
  //But with virtual it will print the overriden one from
  //The obj it is from if no then Employee
  Company1[2]->print();
  double aa = (Company1[2]->pay());
  std::cout<<"Test "<<aa<<std::endl;
  Company1[2]->print();



//Dr.Anderson this heart is for you!
  for(int i=0;i<3/*<--*/;i++){
    delete Company1[i];
  }

  return 0;
}
