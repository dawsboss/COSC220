//Grant dawson COSC 220 Project 1
  #include "StudentDB.h"
//deconstructor
  StudentDB::~StudentDB(){
    studentNode* cursor=head;
    while(head){
      head=head->next;
      delete cursor;
      cursor=head;
    }
    delete [] major;
    delete [] grade;
    delete [] department;
  };

  //copy contructor
  StudentDB::StudentDB(const StudentDB& old){
    if(old.head==nullptr){
      head=nullptr;
    }else{
      studentNode* oldCursor=old.head;
      studentNode* cursor=head;
      while(oldCursor){
        addStudent(oldCursor->s);
        cursor->c=oldCursor->c;
        cursor=cursor->next;
        oldCursor=oldCursor->next;
      }
    }
  };

  //equal operator
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
  }

//constructor with a pre given student
  StudentDB::StudentDB(Student t){
    studentNode* newNode=new studentNode;
    newNode->next=nullptr;
    newNode->s=t;
    head=newNode;
  }

//This will update a desired student with a new given student
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
//This will remove a give student
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

//This will remove a given student info from the list
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

//This will add a new student to the list
  void StudentDB::addStudent(string n,string dob,string m){
    Student temp(n,dob,m);
    addStudent(temp);
  }

//This will print only a specific student and it's courses
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

//This prints all the students with thier courses
  void StudentDB::printAllList(){
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

  //This prings all the student names
  void StudentDB::printAllStudents(){
    studentNode* cursor=head;
    if(!head){
      cout<<"No students in the list"<<endl;
    }
    while(cursor){
        cursor->s.print();
        cursor=cursor->next;
    }
  }



//This will update a specific course to a specfic student
  void StudentDB::updateCourse(Student t,Course z){
    studentNode* cursor=head;
    if(!head){
      cout<<"No students in the list"<<endl;
      return;
    }
    while(cursor){
      if(t==cursor->s){
        cursor->c.update(z,createCourse());
        return;
      }
      cursor=cursor->next;
    }
  }

  //This will remove a desired course form a specific student
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

  //This will add a new course to a specific student give in the parameters
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

//This gives the length/amount of students in the linklist currently
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





//This adds a ne wmajor to the major.txt file
  void StudentDB::addMajorToList(string toAdd){
      Mlength++;
      int i=0;
      ofstream input ("Majors.txt", std::ios_base::app);
      input<<"\n"<<toAdd;
      input.close();
      readMajorList();
    }

    //This reads in the major choices form a file
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

//This returns a newly created student made form user input
  Student StudentDB::createStudent(){
    readMajorList();
    cin.ignore(256, '\n');//NEEDED
    cout<<"What is your name: "<<endl;
    string n;
    getline(cin,n);
    cout<<"What is your date of birth: "<<endl;
    string d;
    getline(cin,d);
    return createStudentMajor(n,d);
  }

  //This asks for what the user whishes to pick their major and if it is not listed will add it to the file
  Student StudentDB::createStudentMajor(string n, string dob){
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
      if(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Invalid input; please re-enter.\n";
        continue;
      }
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

//this functions returns a course created by the user.
  Course StudentDB::createCourse(){
    cin.ignore(256, '\n');//NEEDED
    string dep=createCourseDepartment();
    cout<<"what is the course number: "<<endl;
    string num;
    cin>>num;

    cout<<"What semester did you take this: "<<endl;
    cin.ignore(256, '\n');//NEEDED
    string sem;
    getline(cin,sem);
    char grade=createCourseGrades();
    Course temp(num,dep,sem,grade);
    return temp;
  }


  //This akses the user what department they want to pick form the deparement array
  string StudentDB::createCourseDepartment(){
    //cin.ignore(256, 'n');//NEEDED
    readDepartmentList();
    for(int i=0; i<Dlength; i++){
      cout<<i+1<<")"<<department[i]<<" ";
    }
    cout<<endl;
    while(true){
      cout<<"What department is you class in? If it is not listed type \"0\""<<endl;
      int choice;
      cin>>choice;
      if(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Invalid input; please re-enter.\n";
        continue;
      }
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

  //if the user doesn't have a desired department in our database yet they can add it here
  void StudentDB::addDepartmentToList(string toAdd){
      Dlength++;
      int i=0;
      ofstream input ("Department.txt", std::ios_base::app);
      input<<"\n"<<toAdd;
      input.close();
      readDepartmentList();
    }

    //This reads the deprtments form a file and then populates the department dynamic arrray
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

    //This lists all the [oosible grades to pick from and returns what the user chose]
  char StudentDB::createCourseGrades(){
    //cin.ignore(256, 'n');//NEEDED
    readGradeList();
    for(int i=0; i<Glength; i++){
        cout<<i+1<<")"<<grade[i]<<" ";
    }
    cout<<endl;
    while(true){
      cout<<"What grade did you get (N means not finished yet)"<<endl;
      int choice;
      cin>>choice;
      if(cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Invalid input; please re-enter.\n";
        continue;
      }
      if(choice>0&&choice<=Glength){
        return grade[--choice];
      }
      cout<<choice<<" is not a valid choice!"<<endl;
    }
  }

  //reads in possible grades you got from a file and populates the grades dynamic array
  void StudentDB::readGradeList(){
    //cin.ignore(256, 'n');//NEEDED
      ifstream input ("Grades.txt");
      int i=0;
      string trash;
      while(!input.eof()){
        i++;
        input>>trash;
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

    //This will return a student that the user picked out of the list of all possible students to pick
    Student StudentDB::chooseStudent(){
      cin.ignore(256, '\n');//NEEDED
      studentNode* cursor=head;
      Student fail("Empty","List","Detected");
      if(!head){
        //cout<<"No students in the list"<<endl;
        return fail;
      }
      int i=0;
      int choice;
      while(cursor){
          cout<<i+1<<")";
          cursor->s.print();
          cursor=cursor->next;
          i++;
      }
      cout<<endl;
      while(true){
        cin>>choice;
        if(cin.fail()){
          cin.clear();
          cin.ignore();
          cout << "Invalid input; please re-enter.\n";
          continue;
        }
        if(choice>0&&choice<=i){
          cursor=head;
          for(int i=0;i<choice-1;i++){
            cursor=cursor->next;
          }
          return cursor->s;
        }
        cout<<"Not a valid repsonse"<<endl;
      }
    }

    //This returns a course that the user picked out of all the possibilities form the given student's node
    Course StudentDB::chooseCourse(Student s){
      cin.ignore(256, '\n');//NEEDED
      studentNode* cursor=head;//TODO
      Course fail("Empty","List","Detected",'F');
      int index;
      while(cursor){
        if(cursor->s==s){
          cursor->c.printAllList();
          int numCourse=cursor->c.length();
          int choice;
          if(numCourse!=0){
            while(true){
              cin>>choice;
              if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "Invalid input; please re-enter.\n";
                continue;
              }
              if(choice>0&&choice<=numCourse){
                return cursor->c.chooseCourse(--choice);
              }
              cout<<"Not a valid repsonse"<<endl;
            }
          }else{
            return fail;
          }
        }else{
          cursor=cursor->next;
        }
      }
    }
