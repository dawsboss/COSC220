
  #include "StudentDB.h"

  StudentDB::~StudentDB(){
    studentNode* cursor=head;
    while(head){
      //delete cursor->c;
      head=head->next;
      delete cursor;
      cursor=head;
    }
    delete [] major;
  };
  StudentDB::StudentDB(const StudentDB& old){
    if(old.head==nullptr){
      head=nullptr;
    }else{
      studentNode* oldCursor=old.head;
      while(oldCursor){
        addStudent(oldCursor->s);
        oldCursor=oldCursor->next;
      }
    }
    readMajorList();
  };
  StudentDB* StudentDB::operator=(const StudentDB& x){
    studentNode* oldCursor=x.head;
    while(oldCursor){
      addStudent(oldCursor->s);
      oldCursor=oldCursor->next;
    }
      return (this);
  }

  StudentDB::StudentDB(){
    head=nullptr;
    readMajorList();
  }

  StudentDB::StudentDB(Student t){
    studentNode* newNode=new studentNode;
    newNode->next=nullptr;
    newNode->s=t;
    head=newNode;
    readMajorList();
  }





  void StudentDB::updateStudent(Student replace, Student t){
    studentNode* cursor=head;
    if(!head){
      cout<<"No students in the list"<<endl;
      return;
    }
    while(cursor){
      if(cursor->s==replace){
        cursor->s.setName(t.getName());
        cursor->s.setDOB(t.getDOB());
        cursor->s.setMajor(t.getMajor());
        return;
      }
      cursor=cursor->next;
    }
    cout<<"No student updated!"<<endl;
  }

  void StudentDB::removeStudent(Student rmS){
    studentNode* cursor=head;
    studentNode* prev=head;
    if(!head){
      cout<<"No students in the list"<<endl;
      return;
    }
    if(head->s == rmS){
      head=head->next;
      delete cursor;
      return;
    }
    while(cursor){
      if(cursor->s==rmS){
        prev->next=cursor->next;
        delete cursor;
        return;
      }
      prev=cursor;
      cursor=cursor->next;
    }
    cout<<rmS.getName()<<" was not found it could not be deleted!"<<endl;
  }

  void StudentDB::removeStudent(string n, string dob, string m){
    Student temp(n,dob,m);
    removeStudent(temp);
  }

  void StudentDB::addStudent(Student crS){
    studentNode* cursor=head;
    studentNode* newNode = new studentNode;
    newNode->s=crS;
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

  void StudentDB::addStudent(string n,string dob,string m){
    Student temp(n,dob,m);
    addStudent(temp);
  }

  void StudentDB::printStudent(Student s){
    studentNode* cursor=head;
    if(!head){
      cout<<"No students in the list"<<endl;
      return;
    }
    while(cursor){
      if(s == cursor->s){
        cursor->s.print();
        cursor->c.printAll();
        return;
      }
      cursor=cursor->next;
    }
    cout<<"No student found with "<<s.getName()<<"'s info"<<endl;
  }

  void StudentDB::printAllStudents(){
    studentNode* cursor=head;
    if(!head){
      cout<<"No students in the list"<<endl;
      return;
    }
    while(cursor){
        cursor->s.print();
        cursor->c.printAll();
        cursor=cursor->next;
    }
  }




  void StudentDB::updateCourse(Student t,Course z){
    studentNode* cursor=head;
    if(!head){
      cout<<"No students in the list"<<endl;
      return;
    }
    while(cursor){
      if(t==cursor->s){
        cursor->c.update(z);
        return;
      }
      cursor=cursor->next;
    }
  }
  void StudentDB::removeCourse(Student t, Course z){
    studentNode* cursor=head;
    if(!head){
      cout<<"No students in the list"<<endl;
      return;
    }
    while(cursor){
      if(t==cursor->s){
        cursor->c.remove(z);
        return;
      }
      cursor=cursor->next;
    }
  }

  void StudentDB::addCourse(Student t, Course z){
    studentNode* cursor=head;
    if(!head){
      cout<<"No students in the list"<<endl;
      return;
    }
    while(cursor){
      if(t==cursor->s){
        cursor->c.append(z);
        return;
      }
      cursor=cursor->next;
    }
  }

  int StudentDB::length(){
    studentNode* cursor=head;
    int counter=0;
    if(!head)
      return counter;
    while(cursor){
      counter++;
      cursor=cursor->next;
    }
    return counter;
  }






  void StudentDB::addMajorToList(string toAdd){
      Mlength++;
      int i=0;
      ofstream input ("Majors.txt", std::ios_base::app);
      input<<"\n"<<toAdd;
      input.close();
      readMajorList();
    }
  void StudentDB::readMajorList(){
      ifstream input ("Majors.txt");
      int i=0;
      string trash;
      while(!input.eof()){
        i++;
        input>>trash;
      }
      input.close();
      delete [] major;
      ifstream reInput ("Majors.txt");
      Mlength=i;
      major = new string[i];
      i--;
      while(!reInput.eof()){
        reInput>>major[i];
        i--;
      }
      reInput.close();
    }

  Student StudentDB::createStudent(){
    string trash;
    cout<<"What is your name: "<<endl;
    string n;
    getline(cin,n);
    //cin>>trash;
    cout<<"What is your date of birth: "<<endl;
    string d;
    getline(cin,d);
    //cin>>trash;
    return createStudentMajor(n,d);
  }
  Student StudentDB::createStudentMajor(string n, string dob){
    string trash;
    Student temp;
    temp.setName(n);
    temp.setDOB(dob);
    for(int i=0; i<Mlength; i++){
      cout<<i+1<<")"<<major[i]<<" ";
    }
    cout<<endl;
    while(true){
      cout<<"What is you major? If it is not listed type \"0\""<<endl;
      int choice;
      cin>>choice;
      if(choice==0){
        string newMajor;
        cout<<"What is your major: "<<endl;
        cin>>newMajor;
        addMajorToList(newMajor);
        temp.setMajor(newMajor);
        return temp;
      }else if(choice>0&&choice<=Mlength){
        temp.setMajor(major[--choice]);
        return temp;
      }
      cout<<choice<<" is not a valid choice!"<<endl;
    }
  }


  Course StudentDB::createCourse(){
    string trash;
    string dep=createCourseDepartment();
    cout<<"what is the course number: "<<endl;
    string num;
    cin>>num;
    cin.ignore(256, '\n');//NEEDED
    cout<<"What semester did you take this: "<<endl;
    string sem;
    getline(cin,sem);
    char grade=createCourseGrades();
    Course temp(num,dep,sem,grade);
    return temp;
  }

  string StudentDB::createCourseDepartment(){
    readDepartmentList();
    string trash;
    for(int i=0; i<Dlength; i++){
      cout<<i+1<<")"<<department[i]<<" ";
    }
    cout<<endl;
    while(true){
      cout<<"What department is you class in? If it is not listed type \"0\""<<endl;
      int choice;
      cin>>choice;
      if(choice==0){
        string newDep;
        cout<<"What department is you class from: "<<endl;
        cin>>newDep;
        addMajorToList(newDep);
        return newDep;
      }else if(choice>0&&choice<=Dlength){
        return department[--choice];
      }
      cout<<choice<<" is not a valid choice!"<<endl;
    }
  }
  void StudentDB::addDepartmentToList(string toAdd){
      Dlength++;
      int i=0;
      ofstream input ("Department.txt", std::ios_base::app);
      input<<"\n"<<toAdd;
      input.close();
      readMajorList();
    }
  void StudentDB::readDepartmentList(){
      ifstream input ("Department.txt");
      int i=0;
      string trash;
      while(!input.eof()){
        i++;
        input>>trash;
      }
      input.close();
      delete [] department;
      ifstream reInput ("Department.txt");
      Dlength=i;
      department = new string[i];
      i--;
      while(!reInput.eof()){
        reInput>>department[i];
        i--;
      }
      reInput.close();
    }

  char StudentDB::createCourseGrades(){
    string trash;
    readGradeList();
    for(int i=0; i<Glength; i++){
    }
    cout<<endl;
    while(true){
      cout<<"What was your grade: "<<endl;
      int choice;
      cin>>choice;
      if(choice>0&&choice<=Glength){
        return grade[--choice];
      }
      cout<<choice<<" is not a valid choice!"<<endl;
    }
  }
  void StudentDB::readGradeList(){
      ifstream input ("Grades.txt");
      int i=0;
      string trash;
      while(!input.eof()){
        i++;
        input>>trash;
        cout<<i<<" "<<trash<<endl;
      }
      input.close();
      delete [] grade;
      ifstream reInput ("Grades.txt");
      Glength=i;
      grade = new char[i];
      i--;
      while(!reInput.eof()){
        reInput>>grade[i];
        i--;
      }
      reInput.close();
    }
