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
    void update(Course);
    void remove(Course);
    void printAll();
};

#endif
