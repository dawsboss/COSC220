#include "SUQueue.cpp"
#include "payroll.h"
#include "SUList.h"
#include <iostream>
#include <stdio.h>

int main() {

	/*
	 * @Author: Ryan Rosiak
	 */
	SUQueueArr<int> intQueue;

	std::cout << "Int Queue Tests: " << std::endl;
	std::cout << "Queue Array enqueue Function Tests: " << std::endl;
	std::cout << "First Queue: " << std::endl;
	intQueue.printQueue();
	intQueue.enqueue(5);
	intQueue.enqueue(8);
	intQueue.enqueue(25);
	intQueue.enqueue(7);
	std::cout << "First Queue after 4 enqueues: " << std::endl;
	intQueue.printQueue();
	intQueue.enqueue(40);
	intQueue.enqueue(2);
	intQueue.enqueue(4);
	std::cout << "First Queue, auto resize then 3 more enqueues: " << std::endl;
	intQueue.printQueue();
	intQueue.enqueue(16);
	intQueue.enqueue(1000);
	intQueue.enqueue(4500);
	std::cout << "First Queue, second auto resize then 2 more enqueues: " << std::endl;
	intQueue.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array dequeue Function Tests: " << std::endl;
	SUQueueArr<int> intQueue2;
	intQueue2.enqueue(10);
	intQueue2.enqueue(25);
	intQueue2.enqueue(0);
	std::cout << "Current Queue being worked with: " << std::endl;
	intQueue2.printQueue();
	int deq1, deq2, deq3;
	intQueue2.dequeue(deq1);
	intQueue2.dequeue(deq2);
	intQueue2.dequeue(deq3);
	std::cout << "First dequeue: " << deq1 << "\nSecond dequeue: " << deq2 << "\nThird dequeue: " << deq3 << std::endl;
	std::cout << "List now: " << std::endl;
	intQueue2.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array size Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	intQueue2.printQueue();
	std::cout << "Size of queue: " << intQueue2.size() << std::endl;
	std::cout << "Current List: " << std::endl;
	intQueue.printQueue();
	std::cout << "Size of queue: " << intQueue.size() << std::endl;
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array isEmpty Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	intQueue2.printQueue();
	if (intQueue2.isEmpty()) {
		std::cout << "Queue is empty!!!" << std::endl;
	}
	std::cout << "Current List: " << std::endl;
	intQueue.printQueue();
	if (!intQueue.isEmpty()) {
		std::cout << "Queue is not empty!!!" << std::endl;
	}
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array printQueue Function Tests: " << std::endl;
	std::cout << "Print Queue function demonstrated through all tests" << std::endl;
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array overloaded assignment Tests: " << std::endl;
	std::cout << "First List: " << std::endl;
	intQueue.printQueue();
	SUQueueArr<int> intQueue3;
	std::cout << "Second List: " << std::endl;
	intQueue3.printQueue();
	intQueue3 = intQueue;
	std::cout << "First copied to Second: " << std::endl;
	intQueue3.printQueue();
	SUQueueArr<int> intQueue4;
	intQueue4.enqueue(41);
	intQueue4.enqueue(88);
	intQueue4.enqueue(92);
	std::cout << "Third List: " << std::endl;
	intQueue4.printQueue();
	std::cout << "Third copied to First: " << std::endl;
	intQueue = intQueue4;
	intQueue.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array copy constructor Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	intQueue.printQueue();
	std::cout << "New list Initialized: " << std::endl;
	SUQueueArr<int> intQueue5(intQueue);
	intQueue5.printQueue();
	std::cout << "====================================" << std::endl;

	SUQueueArr<double> doubleQueue;

	std::cout << "Double Queue Tests: " << std::endl;
	std::cout << "Queue Array enqueue Function Tests: " << std::endl;
	std::cout << "First Queue: " << std::endl;
	doubleQueue.printQueue();
	doubleQueue.enqueue(5.2);
	doubleQueue.enqueue(8.4);
	doubleQueue.enqueue(25.621);
	doubleQueue.enqueue(7.0);
	std::cout << "First Queue after 4 enqueues: " << std::endl;
	doubleQueue.printQueue();
	doubleQueue.enqueue(40.15);
	doubleQueue.enqueue(2.2);
	doubleQueue.enqueue(4.441);
	std::cout << "First Queue, auto resize then 3 more enqueues: " << std::endl;
	doubleQueue.printQueue();
	doubleQueue.enqueue(16.5);
	doubleQueue.enqueue(1000.5);
	doubleQueue.enqueue(4500.616);
	std::cout << "First Queue, second auto resize then 2 more enqueues: " << std::endl;
	doubleQueue.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array dequeue Function Tests: " << std::endl;
	SUQueueArr<double> doubleQueue2;
	doubleQueue2.enqueue(10.14);
	doubleQueue2.enqueue(25.18);
	doubleQueue2.enqueue(0.0);
	std::cout << "Current Queue being worked with: " << std::endl;
	doubleQueue2.printQueue();
	double deq4, deq5, deq6;
	doubleQueue2.dequeue(deq4);
	doubleQueue2.dequeue(deq5);
	doubleQueue2.dequeue(deq6);
	std::cout << "First dequeue: " << deq4 << "\nSecond dequeue: " << deq5 << "\nThird dequeue: " << deq6 << std::endl;
	std::cout << "List now: " << std::endl;
	doubleQueue2.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array size Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	doubleQueue2.printQueue();
	std::cout << "Size of queue: " << doubleQueue2.size() << std::endl;
	std::cout << "Current List: " << std::endl;
	doubleQueue.printQueue();
	std::cout << "Size of queue: " << doubleQueue.size() << std::endl;
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array isEmpty Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	doubleQueue2.printQueue();
	if (doubleQueue2.isEmpty()) {
		std::cout << "Queue is empty!!!" << std::endl;
	}
	std::cout << "Current List: " << std::endl;
	doubleQueue.printQueue();
	if (!doubleQueue.isEmpty()) {
		std::cout << "Queue is not empty!!!" << std::endl;
	}
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array printQueue Function Tests: " << std::endl;
	std::cout << "Print Queue function demonstrated through all tests" << std::endl;
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array overloaded assignment Tests: " << std::endl;
	std::cout << "First List: " << std::endl;
	doubleQueue.printQueue();
	SUQueueArr<double> doubleQueue3;
	std::cout << "Second List: " << std::endl;
	doubleQueue3.printQueue();
	doubleQueue3 = doubleQueue;
	std::cout << "First copied to Second: " << std::endl;
	doubleQueue3.printQueue();
	SUQueueArr<double> doubleQueue4;
	doubleQueue4.enqueue(41.5);
	doubleQueue4.enqueue(88.991);
	doubleQueue4.enqueue(92.78);
	std::cout << "Third List: " << std::endl;
	doubleQueue4.printQueue();
	std::cout << "Third copied to First: " << std::endl;
	doubleQueue = doubleQueue4;
	doubleQueue.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array copy constructor Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	doubleQueue.printQueue();
	std::cout << "New list Initialized: " << std::endl;
	SUQueueArr<double> doubleQueue5(doubleQueue);
	doubleQueue5.printQueue();
	std::cout << "====================================" << std::endl;

	SUQueueArr<PayRoll> payrollQueue;
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
	std::cout << "PayRoll Queue Tests: " << std::endl;
	std::cout << "Queue Array enqueue Function Tests: " << std::endl;
	std::cout << "First Queue: " << std::endl;
	payrollQueue.printQueue();
	payrollQueue.enqueue(p1);
	payrollQueue.enqueue(p2);
	payrollQueue.enqueue(p3);
	payrollQueue.enqueue(p4);
	std::cout << "First Queue after 4 enqueues: " << std::endl;
	payrollQueue.printQueue();
	payrollQueue.enqueue(p5);
	payrollQueue.enqueue(p6);
	payrollQueue.enqueue(p7);
	std::cout << "First Queue, auto resize then 3 more enqueues: " << std::endl;
	payrollQueue.printQueue();
	payrollQueue.enqueue(p8);
	payrollQueue.enqueue(p9);
	payrollQueue.enqueue(p10);
	std::cout << "First Queue, second auto resize then 2 more enqueues: " << std::endl;
	payrollQueue.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array dequeue Function Tests: " << std::endl;
	SUQueueArr<PayRoll> payrollQueue2;
	payrollQueue2.enqueue(p10);
	payrollQueue2.enqueue(p2);
	payrollQueue2.enqueue(p3);
	std::cout << "Current Queue being worked with: " << std::endl;
	payrollQueue2.printQueue();
	PayRoll p11, p12, p13;
	payrollQueue2.dequeue(p11);
	payrollQueue2.dequeue(p12);
	payrollQueue2.dequeue(p13);
	std::cout << "First dequeue: " << p11 << "\nSecond dequeue: " << p12 << "\nThird dequeue: " << p13 << std::endl;
	std::cout << "List now: " << std::endl;
	payrollQueue2.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array size Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	payrollQueue2.printQueue();
	std::cout << "Size of queue: " << payrollQueue2.size() << std::endl;
	std::cout << "Current List: " << std::endl;
	payrollQueue.printQueue();
	std::cout << "Size of queue: " << payrollQueue.size() << std::endl;
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array isEmpty Function Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	payrollQueue2.printQueue();
	if (payrollQueue2.isEmpty()) {
		std::cout << "Queue is empty!!!" << std::endl;
	}
	std::cout << "Current List: " << std::endl;
	payrollQueue.printQueue();
	if (!payrollQueue.isEmpty()) {
		std::cout << "Queue is not empty!!!" << std::endl;
	}
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array printQueue Function Tests: " << std::endl;
	std::cout << "Print Queue function demonstrated through all tests" << std::endl;
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array overloaded assignment Tests: " << std::endl;
	std::cout << "First List: " << std::endl;
	payrollQueue.printQueue();
	SUQueueArr<PayRoll> payrollQueue3;
	std::cout << "Second List: " << std::endl;
	payrollQueue3.printQueue();
	payrollQueue3 = payrollQueue;
	std::cout << "First copied to Second: " << std::endl;
	payrollQueue3.printQueue();
	SUQueueArr<PayRoll> payrollQueue4;
	payrollQueue4.enqueue(p7);
	payrollQueue4.enqueue(p1);
	payrollQueue4.enqueue(p5);
	std::cout << "Third List: " << std::endl;
	payrollQueue4.printQueue();
	std::cout << "Third copied to First: " << std::endl;
	payrollQueue = payrollQueue4;
	payrollQueue.printQueue();
	std::cout << "====================================" << std::endl;

	std::cout << "Queue Array copy constructor Tests: " << std::endl;
	std::cout << "Current List: " << std::endl;
	payrollQueue.printQueue();
	std::cout << "New list Initialized: " << std::endl;
	SUQueueArr<PayRoll> payrollQueue5(payrollQueue);
	payrollQueue5.printQueue();
	std::cout << "====================================" << std::endl;

	// SUQueue tests and SUList tests
	/*
	 * @Author: Grant Dawson
	 */
	   PayRoll x;
  	 int y;

 	 SUList<int> myList;
	  SUList<PayRoll> pList;

   SUQueueList<int> iQueueList; // TODO
   SUQueueList<PayRoll> pQueueList; // TODO

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
	std::cout << "+++Unsorted lad+++\n";
  myList.display();

	myList.sort();

	std::cout << "+++Sorted lad+++\n";
	myList.display();

  std::cout << "+++myList[3]+++\n";

	int AA = myList[3];
	std::cout<<AA<<std::endl;

  std::cout << "++++++\n";
  /*
   * Test the SUList using PayRoll
   */
  pList.putFront(PayRoll("Bob", 20, 35));
  pList.putFront(PayRoll("Alice", 10, 35));
  pList.putBack(PayRoll("Charlie", 25, 35));
  pList.putBack(PayRoll("Diana", 10, 35));
  pList.putFront(PayRoll("Eve", 30, 35));

  pList.display();


  std::cout << "+++++++ Queue Lad +++++++++\n";

  iQueueList.enqueue(1000);
  iQueueList.enqueue(1523);
  iQueueList.enqueue(2);
  iQueueList.dequeue(y);
  iQueueList.printQueue();

  std::cout << "++++++++++++\n";

  pQueueList.enqueue(PayRoll("Bob", 20, 35));
  pQueueList.enqueue(PayRoll("Alice", 10, 35));
  pQueueList.enqueue(PayRoll("Charlie",25, 35));
  pQueueList.enqueue(PayRoll("Diana", 10, 35));
  pQueueList.enqueue(PayRoll("Eva", 30, 35));

  pQueueList.printQueue();

  pQueueList.dequeue(x);
  std::cout<<"+++++++ popped lad +++++++++"<<std::endl;
  x.printInfo();
  std::cout << "++++++++++++\n";
  pQueueList.printQueue();

	return 0;
}
