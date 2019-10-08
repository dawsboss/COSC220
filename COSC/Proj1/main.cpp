#include <iostream>
#include "Student.h"
#include "Course.h"
#include "CourseDB.h"
#include "StudentDB.h"

using namespace std;

int main(){
  StudentDB Salisbury;
  Student s1("Grant","July 07, 2000", "Computer Science");
  //Student s2 = Salisbury.createStudent("BillBob", "October 21, 1999");

  Salisbury.addStudent(Salisbury.createStudent());
  Salisbury.addStudent(s1);
  //Salisbury.addStudent(s2);
  Salisbury.addCourse(s1, Salisbury.createCourse());
  Salisbury.addCourse(s1, Salisbury.createCourse());
  //Salisbury.addCourse(s2, Salisbury.createCourse());
  Salisbury.printAllStudents();
}
