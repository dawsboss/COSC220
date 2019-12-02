#ifndef _SUSTACK_H_
#define _SUSTACK_H_
#include <iostream>
#include "SUList.h"

/*
 * @Author: Ryan Rosiak
 * Stack Array Class Definition
 * Implements a stack algorithm on a dynamic array
 */
template<class T>
class SUStackArr {
	private:
		T* arr;
		int capacity;
		int top;

		void enlarge(); // Resizes the array stack and makes it bigger for more data
	public:
		SUStackArr(); // Constructor
		SUStackArr(const SUStackArr&); // Copy Constructor
		~SUStackArr(); // Destructor
		int size() const; // Get the number of elements in the stack
		bool isEmpty() const; // Check if the stack is empty
		void push(const T&); // Pushes an object onto the stack
		void pop(T&); // Pop an object off the stack and store it
		void printStack() const; // Prints the stack from the top, down
		SUStackArr<T>& operator=(const SUStackArr<T>&); // Overloaded Assignment
};

/*
 * @Author: Grant Dawson
 */
template<class DataType>
class SUStackList{
private:

  SUList<DataType> list;

public:
  SUStackList();                   // Constructor
  SUStackList(const SUStackList &); // Copy Constructor
  ~SUStackList();                  // Destructor
  int size() const;               // get the number of elements in the stack
  bool isEmpty() const;           // Check if the stack is empty
  void push(const DataType&);     // Pushes an object onto the stack
  void pop(DataType&);            // Pop an object off the stack and store it
  void printStack() const;        // Prints the stack from the top, down
  SUStackList<DataType>& operator=(const SUStackList<DataType>&); // Assignment operator
};

#endif
