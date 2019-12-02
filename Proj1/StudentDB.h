//Grant dawson COSC 220 Project 1
#ifndef STUDENTDB_H
#define STUDENTDB_H

#include <iostream>
#include "Course.h"
#include "CourseDB.h"
#include "Student.h"
#include <fstream>
#include <string>

using namespace std;

class StudentDB{
private:
  struct studentNode{
    Student s;
    CourseDB c;
    studentNode* next;
  };

  studentNode* head;

  void addMajorToList(string);
  void readMajorList();
  string* major=new string[1];
  int Mlength;
  string* department=new string[1];
  int Dlength;
  char* grade=new char[6];
  int Glength;


public:
  StudentDB();
  StudentDB(Student);

  ~StudentDB();
  StudentDB(const StudentDB&);
  StudentDB* operator=(const StudentDB&);

  void updateStudent(Student, Student);
  //void updateStudent(string,string,string);

  void removeStudent(Student);
  void removeStudent(string,string,string);

  void addStudent(Student);
  void addStudent(string,string,string);

  void printStudent(Student);
  void printAllList();
  void printAllStudents();


  void updateCourse(Student,Course);
  void removeCourse(Student, Course);
  void addCourse(Student, Course);

  int length();

  Student createStudentMajor(string,string);
  Student createStudent();

  Course createCourse();

  void readDepartmentList();
  void addDepartmentToList(string);
  string createCourseDepartment();
  char createCourseGrades();
  void readGradeList();

  Student chooseStudent();
  Course chooseCourse(Student);



};


#endif
