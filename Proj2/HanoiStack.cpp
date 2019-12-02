//Grant dawson COSC 220 Project 2
#include "HanoiStack.h"

using namespace std;

  //Default constructor
  HanoiStack::HanoiStack(){
    head=nullptr;
  };
  //constructor, num makes a new stack with # of disk 
  HanoiStack::HanoiStack(int num){
    head=nullptr;
    HanoiDisc x;
    for(int i=num;i>0;i--){
      x.setSize(i);
      push(x);
    }
  };
  //deconstruction
  HanoiStack::~HanoiStack(){
    DiscNode* cursor=head;
    while(head){
      head=head->next;
      delete cursor;
      cursor=head;
    }
  };
  //copy constructor old is the one getting it's data coppied
  HanoiStack::HanoiStack(const HanoiStack& old){
    DiscNode* oldCursor=old.head;
    int i=0;
    head=nullptr;
    while(oldCursor){
      push(oldCursor->d);
      oldCursor=oldCursor->next;
      i++;
    }
  };
  //= operator RHS right hand side is the one giving up it's data
  HanoiStack* HanoiStack::operator=(const HanoiStack& RHS){
    DiscNode* oldCursor=RHS.head;
    while(oldCursor){
      push(oldCursor->d);
      oldCursor=oldCursor->next;
    }
      return (this);
  }

  //pushes a new disk node into the stack
  void HanoiStack::push(HanoiDisc newD){
    DiscNode* cursor=head;
    DiscNode* newNode=new DiscNode;
      newNode->d=newD;
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

  //pops the "top" off the "stack"/ unlinks and returns the node that was last put in
  HanoiDisc HanoiStack::pop(){
    DiscNode* cursor=head;
    DiscNode* prev=head;
    HanoiDisc temp(-69);
    if(head==nullptr){//if the stack is empty when it tries to pop
      return temp;
    }
    if(head->next==nullptr){//if there is only one item left than pop it
      temp = head->d;
      delete head;
      head=nullptr;
      return temp;
    }

    while(cursor->next){//finds end with a prev
      prev=cursor;
      cursor=cursor->next;
    }
    prev->next=nullptr;
    temp = cursor->d;
    delete cursor;//detatches and deltes end but before it sends it
    return temp;
  }
  
  //this will return the number of nodes in the stack
  int HanoiStack::size() const{
    DiscNode* cursor=head;
    int i=0;
    while(cursor){
      i++;
      cursor=cursor->next;
    }
    return i;
  }

  //prints the stack in the pyrimid form.
  void HanoiStack::print(){
    if(size()==0||!head){
      cout<<"===empty==="<<endl;
      return;
    }
      int i,j,k,t;
      DiscNode* cursor=head;
      DiscNode* printable=head;

      for(i=1;i<=size();i++){
        printable=head;
        t=i+1;
        while(t<=size()&&printable->next){
          printable=printable->next;
          t++;
        }
        for(j=size();j>=((i)-1);j--){
          cout<<" ";
        }
        for(k=1;k<=(printable->d.getSize());k++){
          cout<<printable->d.getSize()<<" ";
        }
        cout<<"\n";
        cursor=cursor->next;
      }
  }

  
  /*void HanoiStack::operator << (const HanoiStack &c){

      if(size()==0||!head){
        cout<<"===empty==="<<endl;
        return;
      }
        int i,j,k,t;
        DiscNode* cursor=head;
        DiscNode* printable=head;

        for(i=1;i<=size();i++){
          printable=head;
          t=i+1;
          while(t<=size()&&printable->next){
            printable=printable->next;
            t++;
          }
          for(j=size();j>=((i)-1);j--){
            cout << " ";
          }
          for(k=1;k<=(printable->d.getSize());k++){
            cout<<printable->d.getSize()<<" ";
          }
          cout<<"\n";
          cursor=cursor->next;
        }
      //return out;
  }*/

  //This will return the value that the node last input is holding (the size of the disk)
  int HanoiStack::peak(){
    DiscNode* cursor=head;
    if(!head){
      return 11;
    }
    while(cursor->next){
      cursor=cursor->next;
    }
    return cursor->d.getSize();
  }

    //== operator RHS is the second Stack that is being compared, returns true if there nodes have the same sizes in the same order
  bool HanoiStack::operator==(const HanoiStack& RHS){
    DiscNode* cursor=head;
    DiscNode* oldCursor=RHS.head;
    if(this->size()!=RHS.size()){
      return false;
    }
    while(cursor){
      if(cursor->d.getSize()!=oldCursor->d.getSize()){
        cout<<"disk size: "<<cursor->d.getSize()<<" "<<oldCursor->d.getSize()<<endl;
        return false;
      }
      cursor=cursor->next;
      oldCursor=oldCursor->next;
    }
    return true;
  }

  //+= this will push a new Disk to the callers stack.
    void HanoiStack::operator+=(HanoiDisc& x){
      push(x);
    }
