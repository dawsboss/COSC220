#include<iostream>
#include<chrono>//chrono
#include <stdlib.h>//rand
#include<time.h>//time
#include<unistd.h>//sleep

using namespace std;

int* makeArray(int len){
  int* rtn=new int[len];
  for(int i=0;i<len;i++){
    rtn[i]=1+rand()%100; //1-100
  }
  return rtn;
}
void Swap(int &s1, int &s2){
  int temp=s2;
  s2=s1;
  s1=temp;
}





void BubbleSort(int*p, int len){
  bool swapped=true;
  while(swapped){
    swapped=false;
    for(int i=0;i<len;i++){
      if(p[i]>p[i+1]){
        Swap(p[i],p[i+1]);
        swapped=true;
      }
    }
  }
}
void BubbleSortV2(int*p, int len){
  bool swapped=true;
  while(swapped){
    swapped=false;
    for(int i=0;i<len;i++){
      if(p[i]>p[i+1]){
        Swap(p[i],p[i+1]);
        swapped=true;
      }
    }
    len--;
  }
}
void SelectionSort(int*p,int len){
  it min;
  for(int i=0;i<len-1;i++){
    min=i;
    for(int j=i=1; j<len;j++){
      if(p[j]<p[min]){
        min=j;
      }
    }
    Swap(p[i],p[min]);
  }
}
void InspectionSort(int*p,int len){
  int j;
  for(int i=1; i<len;i++){
    j=i;
    while(j>0 && (p[j]<p[j-1])){
      Swap(p[j],p[j-1]);
      j=j-1;
    }
  }
}










int main(){
  int* arr=makeArray(1000);

//auto is c++11(most likely) and will set the variable to what the return type is
  auto start = chrono::system_clock::now();//stores current time

    //put sort here TODO

  auto end = chrono::system_clock::now();
  chrono::duration<double> elapsed_second =  end - start;
  time_t end_t = chrono::system_clock::to_time_t(end);//cast time object to time

  cout<<"Finished at "<<ctime()<<" elapsed time "<<elapsed_seconds.count()<<endl;

  return 0;
}
