#ifndef _SUQUEUE_H_
#define _SUQUEUE_H_
#include <iostream>
#include "SUList.h"

/*
 * @Author: Ryan Rosiak
 */
template<class T>
class SUQueueArr {
	private:
		T* arr;
		int capacity;
		int front;
		int rear;

		void enlarge();
		void moveUp();
	public:
		SUQueueArr(); // Constructor
		SUQueueArr(const SUQueueArr&); // Copy Constructor
		~SUQueueArr(); // Destructor
		int size() const; // Gets the number of elements in the queue
		bool isEmpty() const; // Checks if the queue is empty
		void enqueue(const T&); // Enqueues some data to the back of the queue
		void dequeue(T&); // Gets the front element and stores it into the passed parameter
		void printQueue() const; // Prints the queue from the front to the rear
		SUQueueArr<T>& operator=(const SUQueueArr<T>&); // Overloaded Assignment
};

/*
 * @Author: Grant Dawson
 */
template <class DataType>
class SUQueueList{
private:

SUList<DataType> list;

public:
  SUQueueList();                   // Constructor
  SUQueueList(const SUQueueList &); // Copy Constructor
  ~SUQueueList();                  // Destructor
  int size() const;               // get the number of elements in the queue
  bool isEmpty() const;           // Check if the queue is empty
  void enqueue(const DataType&);  // Enqueues some data
  void dequeue(DataType&);        // Get the front element and store it
  void printQueue() const;        // Prints the queue from the front to the rear
  SUQueueList<DataType>& operator=(const SUQueueList<DataType>&); // Assignment operator
};

#endif
