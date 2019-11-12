//Grant dawson COSC 220 Project 1
#include <iostream>
#include "Student.h"
#include "Course.h"
#include "CourseDB.h"
#include "StudentDB.h"

using namespace std;

int main(){
  StudentDB Salisbury;
/*  Student s1("Grant","July 07, 2000", "Computer Science");
  //Student s2 = Salisbury.createStudent("BillBob", "October 21, 1999");

  Salisbury.addStudent(Salisbury.createStudent());
  Salisbury.addStudent(s1);
  //Salisbury.addStudent(s2);
  Salisbury.addCourse(s1, Salisbury.createCourse());
  Salisbury.addCourse(s1, Salisbury.createCourse());
  //Salisbury.addCourse(s2, Salisbury.createCourse());
  Salisbury.printAllList();*/




  Student holderS;
  Course holderC;
  int choice;
  Student fails("Empty","List","Detected");
  Course failc("Empty","List","Detected",'F');
  bool menu=true;
  while(menu){

    cout<<"Menu:\n 1)Create student\n 2)Update student\n 3)Remove student\n 4)Create course\n 5)Update course\n 6)Remove course\n 7)Print all\n 8)Exit menus"<<endl;
    //cin.ignore(256, '\n');//NEEDED
    cin>>choice;
    if(choice==1){
      //This is the choice to add a new studnt to the list
      Salisbury.addStudent(Salisbury.createStudent());
    }else if(choice==2){
      //This is the choice to update a student
      cout<<"Who would you like to update: "<<endl;
      holderS = Salisbury.chooseStudent();
      if(holderS==fails){
        cout<<"No students in list"<<endl;
        continue;
      }
      cout<<"Updated students new info: "<<endl;
      Salisbury.updateStudent(holderS, Salisbury.createStudent());
    }else if(choice==3){
      //This is the choice to remove a student
      Salisbury.removeStudent(Salisbury.chooseStudent());
    }else if(choice==4){
      //This is the choice to add a new course to a specific student
      cout<<"Which student would you like this course to go to: "<<endl;
      holderS = Salisbury.chooseStudent();
      if(holderS==fails){
        cout<<"No students in list"<<endl;
        continue;
      }
      cout<<"Enter the courses info: "<<endl;
      holderC=Salisbury.createCourse();
      Salisbury.addCourse(holderS, holderC);
    }else if(choice==5){
      //This is the choice to update a specific course in a specific student
      cout<<"Which student's course would you like to update: "<<endl;
      holderS = Salisbury.chooseStudent();
      if(holderS==fails){
        cout<<"No students in list"<<endl;
        continue;
      }
      cout<<"Which course would you like to remove:"<<endl;
      holderC=Salisbury.chooseCourse(holderS);
      if(holderC==failc){
        cout<<"No courses in the list"<<endl;
        continue;
      }
      Salisbury.updateCourse(holderS, holderC);
    }else if(choice==6){
      //This is the choice to remove a ourse from a specific student
      cout<<"Which student's course would you like to remove: "<<endl;
      holderS = Salisbury.chooseStudent();
      if(holderS==fails){
        cout<<"No students in list"<<endl;
        continue;
      }
      cout<<"Which course would you like to remove:"<<endl;
      holderC=Salisbury.chooseCourse(holderS);
      if(holderC==failc){
        cout<<"No courses in the list"<<endl;
        continue;
      }
      Salisbury.removeCourse(holderS, holderC);
    }else if(choice==7){
      //This is the choice to print all of both lists
      Salisbury.printAllList();
    }else if(choice==8){
      //This is the choice to exit the program
      menu=false;
    }else{
      cout<<"not an option"<<endl;
    }
  }
}
