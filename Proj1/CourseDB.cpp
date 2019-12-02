//Grant dawson COSC 220 Project 1
#include"CourseDB.h"

using namespace std;
//defual constructor
CourseDB::CourseDB(){
  head=nullptr;
}
//deconstructor
CourseDB::~CourseDB(){
  courseNode* cursor=head;
  while(head){
    head=head->next;
    delete cursor;
    cursor=head;
  }
}
//Copy constructor
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
//= operator
CourseDB* CourseDB::operator=(const CourseDB& x){
  courseNode* oldCursor=x.head;
  while(oldCursor){
    append(oldCursor->course);
    oldCursor=oldCursor->next;
  }
    return (this);
}
//appends a new Course node ot the end with the values of temp
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

//update a given Course to given c
void CourseDB::update(Course c,Course newC){
  courseNode* cursor=head;
  while(cursor){
    if(cursor->course==c){
      cursor->course = newC;
    }
    cursor=cursor->next;
  }
}

//removes a course that is equal too c
//For lab 8 this function was all sorts of messed up
//It would not delete the tail element so iadded that #include
//Now it also has no segfaults
void CourseDB::remove(Course c){
  courseNode* cursor=head;
  courseNode* prev=head;
  if(!head){
    cout<<"No courses in the list"<<endl;
    return;
  }
  if(head->course==c){//This will catch to see if the head is null
    cursor=head;
    head=head->next;
    delete cursor;
    return;
  }
  while(cursor->next){
    if(cursor->course==c){
      prev->next=cursor->next;
      delete cursor;
      return;
    }
    prev=cursor;
    cursor=cursor->next;
  }
//This is the tail catch
  if(cursor){
    if(cursor->course==c){
      prev->next=nullptr;
      delete cursor;
    }
  }
  /*if(cursor==head && prev==head){
    head=head->next;
    delete cursor;
    return;
  }*/
}

//prints all the courses in the list
void CourseDB::printAll(){
  if(!head){
    cout<<"Student not in any courses!"<<endl;
    return;
  }
  courseNode* cursor=head;
  while(cursor){
    //cout<<"Name: "<<cursor->course.getName()<<" Department: "<<cursor->course.getDepartment()<<" Semester: "<<cursor->course.getSemester()<<" Grade: "<<endl;
    cout<<cursor->course.getDepartment()<<":"<<cursor->course.getName()<<" | Semester: "<<cursor->course.getSemester()<<" | Grade: "<<cursor->course.getGrade()<<endl;
    cursor=cursor->next;
  }
}


void CourseDB::printAllList(){
  if(!head){
    cout<<"Student not in any courses!"<<endl;
    return;
  }
  int i=1;
  courseNode* cursor=head;
  while(cursor){
    //cout<<"Name: "<<cursor->course.getName()<<" Department: "<<cursor->course.getDepartment()<<" Semester: "<<cursor->course.getSemester()<<" Grade: "<<endl;
    cout<<i<<")"<<cursor->course.getDepartment()<<":"<<cursor->course.getName()<<" | Semester: "<<cursor->course.getSemester()<<" | Grade: "<<cursor->course.getGrade()<<" "<<endl;
    cursor=cursor->next;
    i++;
  }
}

//returns a course the user choose and it found by what index it was at
Course CourseDB::chooseCourse(int index){
  courseNode* cursor=head;
  for(int i=0;i<index;i++){
    cursor=cursor->next;
  }
  return cursor->course;
}

//This returns the amount of courses in the list starting from 0
int CourseDB::length(){
  courseNode* cursor=head;
  int counter=0;
  if(!head)
    return counter;
  while(cursor){
    counter++;
    cursor=cursor->next;
  }
  return counter;
}
