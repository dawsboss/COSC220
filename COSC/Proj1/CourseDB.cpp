#include"CourseDB.h"

using namespace std;

CourseDB::CourseDB(){
  head=nullptr;
}

CourseDB::~CourseDB(){
  courseNode* cursor=head;
  while(head){
    head=head->next;
    delete cursor;
    cursor=head;
  }
}
CourseDB::CourseDB(const CourseDB& old){
  if(old.head==nullptr){
    head=nullptr;
  }else{
    courseNode* oldCursor=old.head;
    while(oldCursor){
      append(oldCursor->course);
      oldCursor=oldCursor->next;
    }
  }
}
CourseDB* CourseDB::operator=(const CourseDB& x){
  courseNode* oldCursor=x.head;
  while(oldCursor){
    append(oldCursor->course);
    oldCursor=oldCursor->next;
  }
    return (this);
}

void CourseDB::append(Course temp){
  courseNode* cursor=head;
  courseNode* newNode = new courseNode;
  newNode->course=temp;
  newNode->next=nullptr;
  if(head==nullptr){
    head=newNode;
    return;
  }
  while(cursor->next){
    cursor=cursor->next;
  }
  cursor->next=newNode;
}

void CourseDB::update(Course c){
  courseNode* cursor=head;
  while(cursor){
    //if(cursor->course==c){
      cursor->course = c;
    //}
    cursor=cursor->next;
  }
}

void CourseDB::remove(Course c){
  courseNode* cursor=head;
  courseNode* prev=head;

  while(cursor->next){
    prev=cursor;
    cursor=cursor->next;
    //if(cursor->course==c){
      prev->next=cursor->next;
      delete cursor;
    //}
  }
  if(cursor==head && prev==head){
    head=head->next;
    delete cursor;
    return;
  }  courseNode* newNode=new courseNode;
  Course temp("117", "COSC", "Fall 2019", 'A');
  newNode->course = temp;
  head=newNode;
}

void CourseDB::printAll(){
  if(!head){
    cout<<"Student not in any courses!"<<endl;
    cout<<"========================="<<endl;
    return;
  }
  courseNode* cursor=head;
  while(cursor){
    //cout<<"Name: "<<cursor->course.getName()<<" Department: "<<cursor->course.getDepartment()<<" Semester: "<<cursor->course.getSemester()<<" Grade: "<<endl;
    cout<<cursor->course.getDepartment()<<":"<<cursor->course.getName()<<" | Semester: "<<cursor->course.getSemester()<<" | Grade: "<<cursor->course.getGrade()<<endl;
    cursor=cursor->next;
  }
  cout<<"========================="<<endl;
}
