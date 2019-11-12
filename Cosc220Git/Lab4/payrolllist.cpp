//Grant Dawson COSC 220
#include "payrolllist.h"


using namespace std;

PayRollList::PayRollList(){
  head = nullptr;
};

PayRollList::~PayRollList(){

  ListNode* cursor=head;
  while(head){
    head=head->next;
    delete cursor;
    cursor=head;
  }
};
    /*
    * copy constructor, takes another list by reference!
    * Should copy each PayRoll into the list being instantiated
    */

    //Takes all components of another list and puts them into this one
PayRollList::PayRollList(PayRollList& old){
  if(old.head==nullptr){
    head=nullptr;
  }else{
    ListNode* oldCursor=old.head;
    while(oldCursor){
      insert(oldCursor->p);
      oldCursor=oldCursor->next;
    }
  }
};






// Returns the number of items in the list
int PayRollList::length(){
  ListNode* cursor = head;
  int counter=0;
  while(cursor){
    counter++;
    cursor=cursor->next;
  }
  return counter;
}

    // An overloaded index operator
    // Takes an integer index and (if it exists)
    // returns a *reference to* the PayRoll inside it (why?).
    // To use this, we can say myList[5] to get a reference
    // to the sixth element of the list (if present).
    // You may return a null pointer if the object is not present

    //Returns the PayRoll at a given index if one
PayRoll* PayRollList::operator[](int n){
  if(length()>=n && n>=0){
    ListNode* cursor=head;
    int counter=0;
    while(cursor){
      if(counter==n){
	return &(cursor->p);
      }
      cursor=cursor->next;
    }
  }else{
    cout<<"No PayRoll found at "<<n<<endl;
    return nullptr;
  }
}
    // Remove the list item at the specified position
    // (may take advantage of your operator[])

    //removes a index in the list by a given desired index
void PayRollList::remove(int n){
  ListNode* cursor=head;
  ListNode* prev=head;
  if(length()>=n && n>=0){
    if(n==0){
      head=head->next;
      delete cursor;
      return;
    }
    for(int i=0;i<n;i++){
      prev=cursor;
      cursor=cursor->next;
    }
    prev->next=cursor->next;
    delete cursor;
  }else{
    cout<<"PayRoll not deleted, there was no PayRoll at "<<n<<" to delete!"<<endl;
  }


}
    // Copy a PayRoll into a specific position.
    // Be sure to validate the position!
    // (may take advantage of your operator[])

    //overights the PayRoll at a desired index
void PayRollList::assign(int n, PayRoll x){
  if(length()>=n && n>=0){
    ListNode* cursor=head;
    for(int i=0;i<n;i++){
      cursor=cursor->next;
    }
    cursor->p=x;
  }else{
    cout<<"PayRoll not updated, there was no PayRoll at "<<n<<" to update!"<<endl;
  }
}
    // Inserts the PayRoll into the list so that it is now at the
    // specified position (may take advantage of your operator[]).

    //makes a new index in the list but not sorted but at a desired index
void PayRollList::insert(int n, PayRoll x){
  if(length()>=n && n>=0){
    ListNode* cursor = head;
    ListNode* prev = head;
    ListNode* newNode=new ListNode;
    newNode->p=x;
    newNode->next=nullptr;
    if(n==0){
      newNode->next=head->next;
      head=newNode;
      return;
    }
    for(int i=0;i<n;i++){
      prev=cursor;
      cursor=cursor->next;
    }
    prev->next=newNode;
    newNode->next=cursor;

  }else{
    cout<<"PayRoll not added, there was no index at "<<n<<" to put your new PayRoll in!"<<endl;
  }
}






















void PayRollList::insert(string name, float pay, float hours)
{
  PayRoll temp(pay, hours, name);
  ListNode *newNode = new ListNode;
  newNode->p = temp;
  newNode->next=nullptr;
  ListNode* cursor=head;
  ListNode* previous=head;

  if(!head){
    head=newNode;
    return;
  }
  while(cursor->next || pay<head->p.getPay()){
    if(cursor->p.getPay() >= pay){
      if(pay<head->p.getPay()){
	head=newNode;
      }else{
	previous->next=newNode;
      }
      newNode->next=cursor;
      return;
    }
    previous=cursor;
    cursor=cursor->next;
  }
  if(cursor && cursor->p.getPay() >= pay){
      previous->next=newNode;
      newNode->next=cursor;
      return;
  }
    cursor->next = newNode;

}

void PayRollList::insert(PayRoll x){
  insert(x.getName(), x.getPay(), x.getWorkTime());
}

void PayRollList::printPayChecks(){
  ListNode* cursor=head;

  while(cursor){
    cout<<cursor->p.getName()<<" worked "<<cursor->p.getWorkTime()<<" hours and is paid ";
    printf("$ %4.2f", cursor->p.getPay());
    cout<<"/hr so they made";
    printf(" $%4.2f\n", cursor->p.totalPay());
    cursor=cursor->next;
  }
}
