#include "SUStack.cpp"
#include "payroll.h"
#include "SUList.h"
#include <iostream>
#include <stdio.h>

int main() {

	SUStackArr<int> intStack;

	std::cout << "Int Stack Tests: " << std::endl;
	std::cout << "Stack Array push Function Tests: " << std::endl;
	std::cout << "First Stack: " << std::endl;
	intStack.printStack();
	intStack.push(5);
	intStack.push(8);
	intStack.push(25);
	intStack.push(7);
	std::cout << "First Stack after 4 pushes: " << std::endl;
	intStack.printStack();
	intStack.push(40);
	intStack.push(2);
	intStack.push(4);
	std::cout << "First Stack, auto resize then 3 more pushes: " << std::endl;
	intStack.printStack();
	intStack.push(16);
	intStack.push(1000);
	intStack.push(4500);
	std::cout << "First Stack, second auto resize then 2 more push: " << std::endl;
	intStack.printStack();
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array pop Function Tests: " << std::endl;
	SUStackArr<int> intStack2;
	intStack2.push(10);
	intStack2.push(25);
	intStack2.push(0);
	std::cout << "Current Stack being worked with: " << std::endl;
	intStack2.printStack();
	int pop1, pop2, pop3;
	intStack2.pop(pop1);
	intStack2.pop(pop2);
	intStack2.pop(pop3);
	std::cout << "First pop: " << pop1 << "\nSecond pop: " << pop2 << "\nThird pop: " << pop3 << std::endl;
	std::cout << "List now: " << std::endl;
	intStack2.printStack();
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array size Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	intStack2.printStack();
	std::cout << "Size of stack: " << intStack2.size() << std::endl;
	std::cout << "Current List: " << std::endl;
	intStack.printStack();
	std::cout << "Size of stack: " << intStack.size() << std::endl;
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array isEmpty Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	intStack2.printStack();
	if (intStack2.isEmpty()) {
		std::cout << "Stack is empty!" << std::endl;
	}
	std::cout << "Current List: " << std::endl;
	intStack.printStack();
	if (!intStack.isEmpty()) {
		std::cout << "Stack is not empty!" << std::endl;
	}
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array printStack Function Tests: " << std::endl;
	std::cout << "Print Stack function demonstrated through all tests" << std::endl;
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array overloaded assignment Tests: " << std::endl;
	std::cout << "First List: " << std::endl;
	intStack.printStack();
	SUStackArr<int> intStack3;
	std::cout << "Second List: " << std::endl;
	intStack3.printStack();
	intStack3 = intStack;
	std::cout << "First copied to Second: " << std::endl;
	intStack3.printStack();
	SUStackArr<int> intStack4;
	intStack4.push(41);
	intStack4.push(88);
	intStack4.push(92);
	std::cout << "Third List: " << std::endl;
	intStack4.printStack();
	std::cout<< "Third copied to First: " << std::endl;
	intStack = intStack4;
	intStack.printStack();
	std::cout << "=================================" << std::endl;

	std::cout << "Stack Array copy constructor Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	intStack.printStack();
	std::cout << "New list Initialized: " << std::endl;
	SUStackArr<int> intStack5(intStack);
	intStack5.printStack();
	std::cout << "================================="<< std::endl;

	SUStackArr<double> doubleStack;

	std::cout << "Double Stack Tests: " << std::endl;
	std::cout << "Stack Array push Function Tests: " << std::endl;
	std::cout << "First Stack: " << std::endl;
	doubleStack.printStack();
	doubleStack.push(5.25);
	doubleStack.push(8.6);
	doubleStack.push(25.2);
	doubleStack.push(7.898);
	std::cout << "First Stack after 4 pushes: " << std::endl;
	doubleStack.printStack();
	doubleStack.push(40.32);
	doubleStack.push(2.2);
	doubleStack.push(4.5);
	std::cout << "First Stack, auto resize then 3 more pushes: " << std::endl;
	doubleStack.printStack();
	doubleStack.push(16.56);
	doubleStack.push(1000.0);
	doubleStack.push(4500.7);
	std::cout << "First Stack, second auto resize then 2 more push: " << std::endl;
	doubleStack.printStack();
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array pop Function Tests: " << std::endl;
	SUStackArr<double> doubleStack2;
	doubleStack2.push(10.2);
	doubleStack2.push(25.65);
	doubleStack2.push(0.7);
	std::cout << "Current Stack being worked with: " << std::endl;
	doubleStack2.printStack();
	double pop4, pop5, pop6;
	doubleStack2.pop(pop4);
	doubleStack2.pop(pop5);
	doubleStack2.pop(pop6);
	std::cout << "First pop: " << pop4 << "\nSecond pop: " << pop5 << "\nThird pop: " << pop6 << std::endl;
	std::cout << "List now: " << std::endl;
	doubleStack2.printStack();
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array size Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	doubleStack2.printStack();
	std::cout << "Size of stack: " << doubleStack2.size() << std::endl;
	std::cout << "Current List: " << std::endl;
	doubleStack.printStack();
	std::cout << "Size of stack: " << doubleStack.size() << std::endl;
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array isEmpty Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	doubleStack2.printStack();
	if (doubleStack2.isEmpty()) {
		std::cout << "Stack is empty!" << std::endl;
	}
	std::cout << "Current List: " << std::endl;
	doubleStack.printStack();
	if (!doubleStack.isEmpty()) {
		std::cout << "Stack is not empty!" << std::endl;
	}
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array printStack Function Tests: " << std::endl;
	std::cout << "Print Stack function demonstrated through all tests" << std::endl;
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array overloaded assignment Tests: " << std::endl;
	std::cout << "First List: " << std::endl;
	doubleStack.printStack();
	SUStackArr<double> doubleStack3;
	std::cout << "Second List: " << std::endl;
	doubleStack3.printStack();
	doubleStack3 = doubleStack;
	std::cout << "First copied to Second: " << std::endl;
	doubleStack3.printStack();
	SUStackArr<double> doubleStack4;
	doubleStack4.push(41.4);
	doubleStack4.push(88.01);
	doubleStack4.push(92.43);
	std::cout << "Third List: " << std::endl;
	doubleStack4.printStack();
	std::cout<< "Third copied to First: " << std::endl;
	doubleStack = doubleStack4;
	doubleStack.printStack();
	std::cout << "=================================" << std::endl;

	std::cout << "Stack Array copy constructor Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	doubleStack.printStack();
	std::cout << "New list Initialized: " << std::endl;
	SUStackArr<double> doubleStack5(doubleStack);
	doubleStack5.printStack();
	std::cout << "================================="<< std::endl;

	SUStackArr<PayRoll> payrollStack;
	PayRoll p1("Ryan", 25, 32.4);
        PayRoll p2("James", 21, 23);
        PayRoll p3("Skylar", 55, 50);
        PayRoll p4("Margaret", 1, 23);
        PayRoll p5("Hemp", 20, 22);
        PayRoll p6("Leonardo", 25, 28);
        PayRoll p7("Jamison", 22, 59);
        PayRoll p8("Cricket", 45, 50);
        PayRoll p9("Elena", 30, 55);
        PayRoll p10("Andrea", 15, 55);
	std::cout << "PayRoll Stack Tests: " << std::endl;
	std::cout << "Stack Array push Function Tests: " << std::endl;
	std::cout << "First Stack: " << std::endl;
	payrollStack.printStack();
	payrollStack.push(p1);
	payrollStack.push(p2);
	payrollStack.push(p3);
	payrollStack.push(p4);
	std::cout << "First Stack after 4 pushes: " << std::endl;
	payrollStack.printStack();
	payrollStack.push(p5);
	payrollStack.push(p6);
	payrollStack.push(p7);
	std::cout << "First Stack, auto resize then 3 more pushes: " << std::endl;
	payrollStack.printStack();
	payrollStack.push(p8);
	payrollStack.push(p9);
	payrollStack.push(p10);
	std::cout << "First Stack, second auto resize then 2 more push: " << std::endl;
	payrollStack.printStack();
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array pop Function Tests: " << std::endl;
	SUStackArr<PayRoll> payrollStack2;
	payrollStack2.push(p10);
	payrollStack2.push(p2);
	payrollStack2.push(p3);
	std::cout << "Current Stack being worked with: " << std::endl;
	payrollStack2.printStack();
	PayRoll p11, p12, p13;
	payrollStack2.pop(p11);
	payrollStack2.pop(p12);
	payrollStack2.pop(p13);
	std::cout << "First pop: " << p11 << "\nSecond pop: " << p12 << "\nThird pop: " << p13 << std::endl;
	std::cout << "List now: " << std::endl;
	payrollStack2.printStack();
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array size Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	payrollStack2.printStack();
	std::cout << "Size of stack: " << payrollStack2.size() << std::endl;
	std::cout << "Current List: " << std::endl;
	payrollStack.printStack();
	std::cout << "Size of stack: " << payrollStack.size() << std::endl;
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array isEmpty Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	payrollStack2.printStack();
	if (payrollStack2.isEmpty()) {
		std::cout << "Stack is empty!" << std::endl;
	}
	std::cout << "Current List: " << std::endl;
	payrollStack.printStack();
	if (!payrollStack.isEmpty()) {
		std::cout << "Stack is not empty!" << std::endl;
	}
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array printStack Function Tests: " << std::endl;
	std::cout << "Print Stack function demonstrated through all tests" << std::endl;
	std::cout << "================================="<< std::endl;

	std::cout << "Stack Array overloaded assignment Tests: " << std::endl;
	std::cout << "First List: " << std::endl;
	payrollStack.printStack();
	SUStackArr<PayRoll> payrollStack3;
	std::cout << "Second List: " << std::endl;
	payrollStack3.printStack();
	payrollStack3 = payrollStack;
	std::cout << "First copied to Second: " << std::endl;
	payrollStack3.printStack();
	SUStackArr<PayRoll> payrollStack4;
	payrollStack4.push(p7);
	payrollStack4.push(p1);
	payrollStack4.push(p5);
	std::cout << "Third List: " << std::endl;
	payrollStack4.printStack();
	std::cout<< "Third copied to First: " << std::endl;
	payrollStack = payrollStack4;
	payrollStack.printStack();
	std::cout << "=================================" << std::endl;

	std::cout << "Stack Array copy constructor Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	payrollStack.printStack();
	std::cout << "New list Initialized: " << std::endl;
	SUStackArr<PayRoll> payrollStack5(payrollStack);
	payrollStack5.printStack();
	std::cout << "=================SUList, SUStack, SUQueue================"<< std::endl;

	// SUStack tests, SUList in SUQueueDriver file
	/*
	 * @Author: Grant Dawson
	 */
	 PayRoll x;
   int y;

  SUList<int> myList;
  SUList<PayRoll> pList;

  SUStackList<int> iStackList;
  SUStackList<PayRoll> pStackList;
  SUStackList<PayRoll> pStackList2;
	try{
		pStackList.pop(x);
	}catch(std::string n){
		std::cout<<n<<std::endl;
	}catch(...){
		std::cout<<"Unknow error\n";
	}
  /**
   * Test the SUList using ints
   */
  myList.putFront(1);
  myList.putFront(6);
  myList.putFront(2);
  myList.putBack(4);
  myList.putBack(5);
  myList.putFront(3);

  std::cout<<"Does myList contain 100?"<<std::endl;
  if(myList.contains(100)){
    std::cout<<"100 is in the list"<<std::endl;
  }else{
    std::cout<<"100 not in the list"<<std::endl;
  }
  myList.display();

  std::cout << "++++++++++++\n";

  /*
   * Test the SUList using PayRoll
   */
  pList.putFront(PayRoll("Bob", 20, 35));
  pList.putFront(PayRoll("Alice", 10, 35));
  pList.putBack(PayRoll("Diana", 25, 35));
  pList.putBack(PayRoll("Diana", 10, 35));
  pList.putFront(PayRoll("Eve", 30, 35));

  pList.display();

  std::cout << "++++++++++++\n";

  /**
   * Test the SUStack using PayRoll
   */
  pStackList.push(PayRoll("Bob", 20, 35));
  pStackList.push(PayRoll("Alice", 10, 35));
  pStackList.push(PayRoll("Charlie", 25, 35));
  pStackList.push(PayRoll("Diana", 10, 35));
  pStackList.push(PayRoll("Eve", 30, 35));
  pStackList.pop(x);
  pStackList.printStack();
  std::cout<<"+++++++ popped lad +++++++++"<<std::endl;
  x.printInfo();
  std::cout << "++++++++++++\n";
  pStackList.printStack();

  std::cout << "++++++++++++\n";

  iStackList.push(10);
  iStackList.push(102);
  iStackList.push(1);
  iStackList.push(50);

  iStackList.printStack();

  std::cout << "+++++++ =operator +++++++++\n";

  pStackList2 = pStackList;
  pStackList2.printStack();

	return 0;
}
