//Grant dawson COSC 220 Project 1
#ifndef COURSEDB_H
#define COURSEDB_H

#include <iostream>
#include "Course.h"

using namespace std;

class CourseDB{
  private:
    struct courseNode{
      Course course;
      courseNode* next;
    };
    courseNode* head;
  public:
    CourseDB();

    ~CourseDB();
    CourseDB(const CourseDB&);
    CourseDB* operator=(const CourseDB&);


    void append(Course);
    void update(Course,Course);
    void remove(Course);
    void printAll();
    void printAllList();
    Course chooseCourse(int);
    int length();
};

#endif
