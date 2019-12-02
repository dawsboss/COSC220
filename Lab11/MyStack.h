#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include "PayRoll.h"

template <class T>
class MyStack{
private:
  struct Node{
    T data;
    Node* next;
  };
  Node* head;
public:
  MyStack();
  ~MyStack();
  MyStack(const MyStack&);
  MyStack operator=(const MyStack&);

  void push(T);
  T pop();
  T peak();
  int size();
  void print();
};
//defualt constructor
template <class T>
MyStack<T>::MyStack(){
  head=nullptr;
}
//deconstructor
template <class T>
MyStack<T>::~MyStack(){
  Node* cursor;
  while(head){
    cursor=head;
    head=head->next;
    delete cursor;
  }
}
//copy constructor
template <class T>
MyStack<T>::MyStack(const MyStack& old){
  if(old.head==nullptr){//checks to see if there is a old head
    head=nullptr;
  }else{//if there is then
    Node* oldCursor=old.head;
    while(oldCursor){//pushes everything over
      push(oldCursor->p);
      oldCursor=oldCursor->next;
    }
  }
};
//setting the left Stack obj to the values from the obj on the right
template <class T>
MyStack<T> MyStack<T>::operator=(const MyStack& x){
  Node* oldCursor=x.head;
  while(oldCursor){
    push(oldCursor->p);
    oldCursor=oldCursor->next;
  }
    return *(this);
}
//This will slap the data on to the end of the list
template <class T>
void MyStack<T>::push(T newData){
    Node* cursor=head;
    Node* newNode=new Node;
      newNode->data=newData;
      newNode->next=nullptr;

      if(head==nullptr){
        head=newNode;
        return;
      }
      while(cursor->next!=nullptr){
        cursor=cursor->next;
      }
      cursor->next=newNode;
}
//This will delink the tail node and give it's data back to the caller
template <class T>
T MyStack<T>::pop(){
  Node* cursor=head;
  Node* prev=head;
  T temp;
  if(head==nullptr){//if the stack is empty when it tries to pop
    throw -1;
  }
  if(head->next==nullptr){//if there is only one item left than pop it
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
  return temp;
}
//This will send back the data that the node is holding on top
template <class T>
T MyStack<T>::peak(){
  if(!head){
    std::cout<<"Stack epmty"<<std::endl;
    throw -1;
  }
  Node* cursor=head;
  while(cursor->next){
    cursor=cursor->next;
  }
  return cursor->data;
}
//This will return the number of nodes that are in the list at the time of call
template<class T>
int MyStack<T>::size(){
  if(!head){
    cout<<"Shit is empty"<<endl;
  }
  Node*cursor=head;
  int counter=0;
  while(cursor){
    counter++;
    cursor=cursor->next;
  }
  return counter;
}
//This will print the current list the way it is
//either make a new template overload or have a << operator for you class
template <class T>
void MyStack<T>::print(){
  Node* cursor=head;
  if(!head){
    cout<<"Shit is empty"<<endl;
  }
  while(cursor){
    std::cout<<cursor->data<<std::endl;
    cursor=cursor->next;
  }
}
//If the list is a PayRoll and I know it doesn't have a << operator than it will run this
template <>
void MyStack<PayRoll>::print(){
  Node* cursor=head;
  while(cursor){
    cursor->data.printInfo();
    cursor=cursor->next;
  }
}

#endif
