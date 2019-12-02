#include<iostream>
//#include "SUList.h"
#include "SUStack.h"
#include "SUQueue.h"
//#include "PayRoll.h"

/**
 * This program provides a slightly-more-than-minimal
 * example of a program that makes use of the various
 * classes defined in the SULibrary project. It tests
 * only some of the SUList an SUStack methods, with
 * some output to verify the results.
 *
 * It only runs partial tests for three of the classes.
 * You should write more on your own, but this can
 * serve as a sanity-check to get started.
 *
 * Be sure to think about edge cases!
 *
 * Must be compiled with:
 *  - PayRoll class method definitions
 *  - Templated definitions
 */

int main(){

  /*
   * First, make sure our templates are available.
   */
   PayRoll x;
   int y;

  SUList<int> myList;
  SUList<PayRoll> pList;

  // SUStackArr<int> iStackArr; // TODO
  // SUStackArr<PayRoll> pStackArr; // TODO
   SUStackList<int> iStackList;
   SUStackList<PayRoll> pStackList;
   SUStackList<PayRoll> pStackList2;

  // SUQueueArr<int> iQueueArr; // TODO
  // SUQueueArr<PayRoll> pQueueArr; // TODO
   SUQueueList<int> iQueueList; // TODO
   SUQueueList<PayRoll> pQueueList; // TODO

  /**
   * Test the SUList using ints
   */
   try{
     myList.getFront();
   }catch(string n){
     std::cout<<n.c_str()<<std::endl;
   }
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
   try{
     pList.getFront();
   }catch(string n){
     std::cout<<n.c_str()<<std::endl;
   }
  pList.putFront(PayRoll( 20, 35,"Bob"));
  pList.putFront(PayRoll(10, 35,"Alice"));
  pList.putBack(PayRoll(25, 35,"Charlie"));
  pList.putBack(PayRoll(10, 35,"Diana"));
  pList.putFront(PayRoll(30, 35,"Eve"));

  pList.display();

  std::cout << "++++++++++++\n";

  /**
   * Test the SUStack using PayRoll
   */
  pStackList.push(PayRoll( 20, 35,"Bob"));
  pStackList.push(PayRoll(10, 35,"Alice"));
  pStackList.push(PayRoll(25, 35,"Charlie"));
  pStackList.push(PayRoll(10, 35,"Diana"));
  pStackList.push(PayRoll(30, 35,"Eve"));
  try{
  pStackList.pop(x);
  }catch(string n){
    std::cout<<n.c_str()<<std::endl;
  }
  pStackList.printStack();
  std::cout<<"+++++++ popped lad +++++++++"<<endl;
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

  std::cout << "+++++++ Queue Lad +++++++++\n";
  try{
    iQueueList.dequeue(y);
  }catch(string n){
    std::cout<<n.c_str()<<std::endl;
  }
  iQueueList.enqueue(1000);
  iQueueList.enqueue(1523);
  iQueueList.enqueue(2);
  try{
    iQueueList.dequeue(y);
  }catch(string n){
    std::cout<<n.c_str()<<std::endl;
  }
  iQueueList.printQueue();

  std::cout << "++++++++++++\n";

  pQueueList.enqueue(PayRoll( 20, 35,"Bob"));
  pQueueList.enqueue(PayRoll(10, 35,"Alice"));
  pQueueList.enqueue(PayRoll(25, 35,"Charlie"));
  pQueueList.enqueue(PayRoll(10, 35,"Diana"));
  pQueueList.enqueue(PayRoll(30, 35,"Eve"));

  pQueueList.printQueue();
  try{
    pQueueList.dequeue(x);
  }catch(string n){
    std::cout<<n.c_str()<<std::endl;
  }
  std::cout<<"+++++++ popped lad +++++++++"<<endl;
  x.printInfo();
  std::cout << "++++++++++++\n";
  pQueueList.printQueue();
  return 0;
}
