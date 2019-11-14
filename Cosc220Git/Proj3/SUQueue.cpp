#include "SUQueue.h"

//defualt constructor
template<class DataType>
SUQueueList<DataType>::SUQueueList(){}

//Deconstructor
template<class DataType>
SUQueueList<DataType>::~SUQueueList(){
  //delete list;
}

//Copy constructor
template<class DataType>
SUQueueList<DataType>::SUQueueList(const SUQueueList &old){
  list=old.list;
}

//returns th current size of the queue at the time of call
template<class DataType>
int SUQueueList<DataType>::size() const{
  return list.size();
}

//This will return if the queue is empty or not
template<class DataType>
bool SUQueueList<DataType>::isEmpty() const{
  if(list.size()==0)
    return true;
  return false;
}

//This will add a new Node to the front of the queue
template<class DataType>
void SUQueueList<DataType>::enqueue(const DataType& x){
   list.putBack(x);
}
//This will pop the front of the queue off and return it
template<class DataType>
void SUQueueList<DataType>::dequeue(DataType& x){
  try{
    x=list.getFront();
  }catch(int n){
    if(n==-1)
      throw "Queue is empty!";
  }catch(...){
    throw "An unknown error has occured...";
  }
}

//This will print the qholw queue
template<class DataType>
void SUQueueList<DataType>::printQueue() const{
  list.display();
}

//
template<class DataType>
SUQueueList<DataType>& SUQueueList<DataType>::operator=(const SUQueueList<DataType> &old){
  if(this==old){
    return *this;
  }
  list=old.list;
  return *this;
}
