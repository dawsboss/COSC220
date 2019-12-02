#include <iostream>

using namespace std;

struct Node {
  int value;
  Node* next;
  // Constructor, only in C++!
  Node(){
    value = 0;
    next = nullptr;
  }
  // Non-default ctor, okay in C++
  Node(int n){
    value = n;
    next = nullptr;
  }
};
//deletes the given list
void NodeDeletus(Node* head){
  if (!head)
      return;
  NodeDeletus(head->next);
  delete head;
}

//returns the length of the list
int length(Node* head){
  if(!head){
    return 0;
  }
  return length(head->next)+1;
}

//prints front to back
void print(Node* head){
  if(!head){
    return;
  }
  cout<<head->value<<" "<<endl;
  return print(head->next);
}

//prints from back to forward
void reversePrint(Node* head){
  if(!head){
    return;
  }
  reversePrint(head->next);
  cout<<head->value<<endl;
}

//puts a number in the correct order to be sorted in a given list
Node* insertSorted(Node* head, int size){
  if(!head){
    head=new Node(size);
    return head;
  }else if(size<head->value){
    Node* temp=new Node(size);
    temp->next=head;
    return temp;
  }else if(!head->next){
    head->next=new Node(size);
    return head;
  }else if(head->next->value>size){
    Node* temp=new Node(size);
    temp->next=head->next;
    head->next=temp;
    return head;
  }
  head->next=insertSorted(head->next, size);
  return head;
}

//Slaps a list to the end of the other, no sorting
//Takes the second parameter and puts it on the end of the first
Node* append(Node* head1, Node* head2){
  if(!head1){
    head1=head2;
    return head1;
  }else if(!head1->next){
    head1->next=head2;
    return head1;
  }
  append(head1->next, head2);
  return head1;
}

//unused - This was my first time where I did not have it return the delete noded
Node* remove(Node* head, int rmN){
  if(!head){
    cout<<rmN<<" was not found in the list"<<endl;
    return head;
  }else if(head->next && head->next->value==rmN){
    Node* tmp = head->next;
    head->next=head->next->next;
    delete tmp;
    return head;
  }else if(head->value==rmN){
    Node* tmp = head;
    head=head->next;
    delete tmp;
    return head;
  }
  Node* rtn=remove(head->next, rmN);
  return head;
}
//This is the version used in the main
//removes a node with the given value (first one found) and then returns what it deleted
Node* REEremove(Node* head, int rmN){
  if(!head){
    cout<<rmN<<" was not found in the list"<<endl;
    return head;
  }else if(head->next && head->next->value==rmN){
    Node* tmp = head->next;
    Node* rtn1 = new Node(tmp->value);
    head->next=head->next->next;
    delete tmp;
    return rtn1;
  }else if(head->value==rmN){
    Node* tmp = head;
    Node* rtn2 = new Node(tmp->value);
    head=head->next;
    delete tmp;
    return rtn2;
  }
  Node* rtn3=remove(head->next, rmN);
  return rtn3;
}

//makes what was on the back to the head, makes the next pointers point the other dirrection
Node* reverse(Node* head)
{

  if(!head){
    return nullptr;
  }
  if(!head->next){
    return head;
  }
  Node* back = reverse(head->next);
  back = append(back,head);
  head->next = nullptr;
  return back;
}





int main(){
  Node* head=new Node(7);
  head = insertSorted(insertSorted(insertSorted(insertSorted(head,20),8),2),9);
  cout<<"head insertSorted:"<<endl;
  print(head);
  cout<<endl;
  cout<<"head print backwards: "<<endl;
  reversePrint(head);
  cout<<"head removed 7"<<endl;
  Node* yeeted=REEremove(head,7);
  print(yeeted);
  cout<<"List mineus 7"<<endl;
  print(head);
  cout<<endl;
  cout<<"reverse head: "<<endl;
  head = reverse(head);
  print(head);
  cout<<endl;
  cout<<"Head1 insertsort: "<<endl;
  Node* head1=new Node(10);
  head1 = insertSorted(insertSorted(insertSorted(insertSorted(head1,2),8),20),9);
  print(head1);
  cout<<"append head to head1: "<<endl;
  head1 = append(head1,head);
  print(head1);
  NodeDeletus(yeeted);
  NodeDeletus(head1);
  return 0;
}
