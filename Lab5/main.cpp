#include "PayRollStack.h"
#include "PayRoll.h"
#include <fstream>

using namespace std;

int main(){
  PayRollStack test;

  ifstream input ("inputs.txt");
  int i=0;
  string name;
  float payment, workTime;
  while(!input.eof()){//brings in file and then copies and pushes it all till there is no more
    input>>name;
    input>>payment;
    input>>workTime;
    PayRoll temp(payment, workTime, name);
    test.push(temp);
  }
  input.close();


  PayRoll x(100, 23.5, "Grant");
  test.push(x);
  PayRoll y(1,1,"Joe");
  PayRoll z(15, 30,"Brock");
  test.push(y);//shows push feature
  test.push(z);
  test.push(y);

  PayRollStack bigLad;
  bigLad=test;
  i=test.size();
  while(i>=0){//prints the list but pops them all out to do so
    PayRoll t = test.pop();
    t.printInfo();
    i--;
    cout<<"-----=-----"<<endl;
  }
  test.pop();

  //testing the = operator overload

  cout<<"++++++++++++++"<<endl;
  cout<<"= operator"<<endl;
  cout<<"++++++++++++++"<<endl;
  i=bigLad.size();
  while(i>=0){//reprints the last one but shows my = operator is working
    PayRoll t = bigLad.pop();
    t.printInfo();
    i--;
    cout<<"-----=-----"<<endl;
  }
}
