#include<iostream>
#include "SUList.h"
//#include "SUStack.h"
//#include "SUQueue.h"
#include "PayRoll.h"

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

  SUList<int> myList;
  SUList<PayRoll> pList;

  //SUStackArr<int> iStackArr; // TODO
  //SUStackArr<PayRoll> pStackArr; // TODO
  //SUStackList<int> iStackList; // TODO
  //SUStackList<PayRoll> pStackList;

  //SUQueueArr<int> iQueueArr; // TODO
  //SUQueueArr<PayRoll> pQueueArr; // TODO
  //SUQueueList<int> iQueueList; // TODO
  //SUQueueList<PayRoll> pQueueList; // TODO

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

  /**
   * Test the SUList using PayRoll
   */
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
  /*pStackList.push(PayRoll("Bob", 20, 35));
  pStackList.push(PayRoll("Alice", 20, 35));
  pStackList.push(PayRoll("Charlie", 20, 35));
  pStackList.push(PayRoll("Diana", 20, 35));
  pStackList.push(PayRoll("Eve", 20, 35));
  pStackList.pop().printCheck();*/

  return 0;
}

/** OUTPUT OF THIS PROGRAM

3
2
6
1
4
5
++++++++++++
=======================
Name:	Eve
Rate:	35
Hours:	30
Total:	1050

=======================
Name:	Alice
Rate:	35
Hours:	10
Total:	350

=======================
Name:	Bob
Rate:	35
Hours:	20
Total:	700

=======================
Name:	Charlie
Rate:	35
Hours:	25
Total:	875

=======================
Name:	Diana
Rate:	35
Hours:	10
Total:	350

++++++++++++
=======================
Name:	Eve
Rate:	35
Hours:	20
Total:	700

*/
