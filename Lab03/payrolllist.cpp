   
#include "payrolllist.h"


using namespace std;

PayRollList::PayRollList(){
  head = nullptr;
};

PayRollList::~PayRollList(){//go through the whole list dealeteing each then finally both pointers

  ListNode* cursor=head;
  while(head){
    head=head->next;
    delete cursor;
    cursor=head;
  }
};

void PayRollList::insert(string name, float pay, float hours)//inserts a new node in sorted order by its pay/hr
{
  PayRoll temp(pay, hours, name);
  ListNode *newNode = new ListNode;
  newNode->p = temp;
  newNode->next=nullptr;
  ListNode* cursor=head;
  ListNode* previous=head;

  if(!head){//if head is null get the list started
    head=newNode;
    return;
  }
  while(cursor->next || pay<head->p.getPay()){
    if(cursor->p.getPay() >= pay){
      if(pay<head->p.getPay()){//if there is a new lowest
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
  if(cursor && cursor->p.getPay() >= pay){// if the while fails but they would still fit in the body since the first few iderations there isn't enough data
      previous->next=newNode;
      newNode->next=cursor;
      return;
  }
    cursor->next = newNode;  //if there is a new max and spill over my conditionals

}

void PayRollList::insert(PayRoll x){//takes a premade oayroll obj and just gives it's data to the other insert function.
  insert(x.getName(), x.getPay(), x.getWorkTime());
}

void PayRollList::printPayChecks(){//prints out each
  ListNode* cursor=head;

  while(cursor){ // for ever cursor print its info in this sentence
    cout<<cursor->p.getName()<<" worked "<<cursor->p.getWorkTime()<<" hours and is paid ";
    printf("$ %4.2f", cursor->p.getPay());
    cout<<"/hr so they made";
    printf(" $%4.2f\n", cursor->p.totalPay());//formatting to have 2 decimal places
    cursor=cursor->next;
  }
}
