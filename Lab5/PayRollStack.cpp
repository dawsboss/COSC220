//Grant Dawson COSC220
#include "PayRollStack.h"

PayRollStack::PayRollStack(){
  head=nullptr;
};
PayRollStack::PayRollStack(const PayRollStack& old){
  if(old.head==nullptr){//checks to see if there is a old head
    head=nullptr;
  }else{//if there is then
    StackNode* oldCursor=old.head;
    while(oldCursor){//pushes everything over
      push(oldCursor->p);
      oldCursor=oldCursor->next;
    }
  }
};

//setting the left Stack obj to the values from the obj on the right
PayRollStack* PayRollStack::operator=(const PayRollStack&x){
  StackNode* oldCursor=x.head;
  while(oldCursor){
    push(oldCursor->p);
    oldCursor=oldCursor->next;
  }
    return (this);
}

PayRollStack::~PayRollStack(){//destructor

  StackNode* cursor=head;
  while(head){
    head=head->next;
    delete cursor;
    cursor=head;
  }
};
// Alternative, but common, method:
// instead of using a return, take the destination container
// as a parameter to the pop function
void PayRollStack::push(PayRoll p){
  StackNode* cursor=head;
  StackNode* newNode = new StackNode;
  newNode->p=p;
  newNode->next=nullptr;
  if(head==nullptr){
    head=newNode;
    return;
  }
  while(cursor->next){//goes to end of list to put new node
    cursor=cursor->next;
  }
  cursor->next=newNode;
}

// Returns the payroll object that was most recently pushed
PayRoll PayRollStack::pop(){
  StackNode* cursor=head;
  StackNode* prev=head;
  PayRoll temp(0,0,"John Doe");
  if(!head){//if the stack is empty when it tries to pop
    std::cout<<"==========Stack empty=========="<<std::endl;
    return temp;
  }
  if(!head->next){//if there is only one item left than pop it
    temp = head->p;
    delete head;
    head=nullptr;
    return temp;
  }

  while(cursor->next){//finds end with a prev
    prev=cursor;
    cursor=cursor->next;
  }
  prev->next=nullptr;
  temp = cursor->p;
  delete cursor;//detatches and deltes end but before it sends it
  return temp;
}
void PayRollStack::pop(PayRoll& x){//pops and does the same thing but in a diffrent way
  x=pop();//calls the other  pop but in another useful way
}

// Returns the number of elements on the stack
int PayRollStack::size(){
  StackNode* cursor = head;
  int counter=0;
  while(cursor){//counter till cursor is null
    counter++;
    cursor=cursor->next;
  }
  return counter;
}
