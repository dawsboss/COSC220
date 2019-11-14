#include "SUList.h"
#ifndef SUQUEUE_H
#define SUQUEUE_H

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
