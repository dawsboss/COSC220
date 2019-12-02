#ifndef SULIST_H
#define SULIST_H

#include <iostream>
#include "PayRoll.h"

template <class DataType>
class SUList{
private:
  struct ListNode{     // The nodes of the list
    DataType data;      // The data stored in the node
    ListNode* next;     // The next node in the list
  };
  ListNode* head;      // The front of the list
  ListNode* tail;      // The last node of the list
public:
  SUList();                      // Default ctor
  SUList(const SUList&);         // Copy ctor
  ~SUList();                     // Destructor
  DataType getFront();           // Remove & return the front
  DataType getBack();            // Remove & return the back
  void putFront(const DataType&);// Add to the front
  void putBack(const DataType&); // Add to the back

  int size() const;              // Returns the number of elements
  bool contains(const DataType&);// Tests for membership
  SUList<DataType>& operator=(const SUList<DataType>&); // Overloaded assignment
  void display();
};
//defualt constructor
template<class DataType>
SUList<DataType>::SUList(){
  head=nullptr;
  tail=nullptr;
}
//Copy constructor
template<class DataType>
SUList<DataType>::SUList(const SUList& old){
  if(old.head==nullptr){//checks to see if there is a old head
    head=nullptr;
  }else{//if there is then
    ListNode* oldCursor=old.head;
    while(oldCursor){//pushes everything over
      push(oldCursor->data);
      oldCursor=oldCursor->next;
    }
  }
};
//equals overloaded operator
template<class DataType>
  SUList<DataType>& SUList<DataType>::operator=(const SUList<DataType>& old){
    ListNode* oldCursor=old.head;
    while(oldCursor){
      push(oldCursor->data);
      oldCursor=oldCursor->next;
    }
  return *(this);
  }
//Deconstructor
template<class DataType>
SUList<DataType>::~SUList(){
  ListNode* cursor=head;
  while(head){
    cursor=head;
    head=head->next;
    delete cursor;
  }
}
//Pops the front/head
template<class DataType>
DataType SUList<DataType>::getFront(){
  ListNode* cursor=head;
  DataType rtn;
  //TODO Need to fix if there is no head
  if(!head){
    throw -1;
  }
  if(!head->next){
    rtn=head->data;
    delete head;
    head=nullptr;
    return rtn;
  }
  rtn=head->data;
  head=head->next;
  delete cursor;
  return rtn;
}
//pops the end of the list
template<class DataType>
DataType SUList<DataType>::getBack(){
  ListNode* cursor=head;
  ListNode* prev=head;
  DataType temp;
  DataType rtn;
  if(!head){//if the stack is empty when it tries to pop
    throw -1;
  }
  if(!head->next){//if there is only one item left than pop it
    temp = head->data;
    delete head;
    head=nullptr;
    return temp;
  }
  while(cursor->next){//finds end with a prev
    prev=cursor;
    cursor=cursor->next;
  }
  prev->next=nullptr;
  temp = cursor->data;
  delete cursor;//detatches and deltes end but before it sends it
  return rtn;
}
//This will push a new dataType onto the front of the list
template<class DataType>
void SUList<DataType>::putFront(const DataType&x){
  ListNode* newNode = new ListNode;
  newNode->data=x;
  newNode->next=head;
  head=newNode;
}
//This will push a new Datatype into the bakc of the list
template<class DataType>
void SUList<DataType>::putBack(const DataType&x){
  ListNode* newNode = new ListNode;
  newNode->data=x;
  newNode->next=nullptr;
  ListNode* cursor=head;
  while(cursor->next){
    cursor=cursor->next;
  }
  cursor->next=newNode;
}
//This will return the number of links in the list
template<class DataType>
int SUList<DataType>::size()const{
  int counter=0;
  ListNode* cursor=head;
  int coutner=1;
  while(cursor){
    counter++;
  }
  return counter;
}
//checks to see if there is a desired DataType in the list
//NOTE: This function will require that the datta type has the == operator
template<class DataType>
bool SUList<DataType>::contains(const DataType&x){
  ListNode* cursor=head;
  while(cursor){
    if(cursor->data==x){
      return true;
    }
    cursor=cursor->next;
  }
  return false;
}
//Display requires the overloaded << or you make your own overloaded tamplate
template<class DataType>
void SUList<DataType>::display(){
  ListNode* cursor=head;
  if(!head){
    std::cout<<"Empty list!"<<std::endl;
    return;
  }
  while(cursor){
    cout<<cursor->data<<endl;
    cursor=cursor->next;
  }

}
//Display overloaded for Payroll
template<>
void SUList<PayRoll>::display(){
  ListNode* cursor=head;
  if(!head){
    std::cout<<"Empty list!"<<std::endl;
    return;
  }
  while(cursor){
    cursor->data.printInfo();
    cursor=cursor->next;
  }

}
#endif
