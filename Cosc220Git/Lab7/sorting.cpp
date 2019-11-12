#include<iostream>
#include<chrono>//chrono
#include <stdlib.h>//rand
#include<time.h>//time
#include<unistd.h>//sleep

using namespace std;

  long swapCounter=0;

//Used to make an dynamic array with th given size
int* makeArray(int len){
  int* rtn=new int[len];
  for(int i=0;i<len;i++){
    rtn[i]=1+rand()%100; //1-100
  }
  return rtn;
}
//Swaps two indexes with one another
void Swap(int &s1, int &s2){
  int temp=s2;
  s2=s1;
  s1=temp;
  swapCounter++;
}
bool isSorted(int* p,int len){
  for(int i=1;i<len;i++){
    if(p[i-1]>p[i]){
      return false;
    }
  }
  return true;
}
//Given Bubble Sort
int BubbleSort(int*p, int len){
  swapCounter=0;
  bool swapped=true;
  while(swapped){
    swapped=false;
    for(int i=0;i<len-1;i++){
      if(p[i]>p[i+1]){
        Swap(p[i],p[i+1]);
        swapped=true;
      }
    }
  }
}
//Given Selection Sort
int SelectionSort(int* p, int len){
  swapCounter=0;
  int min;
  for(int i=0;i<len-1;i++){
    min=i;
    for(int j=i; j<len;j++){
      if(p[j]<p[min]){
        min=j;
      }
    }
    Swap(p[i],p[min]);
  }
}
//Given Inspection Sort
int InspectionSort(int* p, int len){
  swapCounter=0;
  int j;
  for(int i=1; i<len;i++){
    j=i;
    while(j>0 && (p[j]<p[j-1])){
      Swap(p[j],p[j-1]);
      j=j-1;
    }
  }
}
void BackwardsSorter(int* p, int len){
  int j;
  for(int i=0; i<len;i++){
    j=i;
    while(j>0 && (p[j]>p[j-1])){
      Swap(p[j],p[j-1]);
      j--;
    }
  }
}

int main(){
  srand(time(NULL));
  int len=6;
  int length[]={1000,5000,10000,50000,100000};
  int* arr;

  /*arr=makeArray(10);
  BackwardsSorter(arr,10);
  for(int i=0;i<10;i++){
    cout<<arr[i]<<endl;
  }
  delete [] arr;*/
//auto is c++11(most likely) and will set the variable to what the return type is
for(int j=0;j<len;j++){
  for(int i=0;i<3;i++){
    arr=makeArray(length[j]);
    if(i==0){
      InspectionSort(arr, length[j]);
      cout<<"Desired array in ascending order: "<<endl;
    }else if(i==1){
      BackwardsSorter(arr, length[j]);
      cout<<"Desired array in decending order"<<endl;
    }else if(i==2){
      cout<<"Desired array is randomly order"<<endl;
    }
    auto start = chrono::system_clock::now();//stores current time

      BubbleSort(arr, length[j]);

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds =  end - start;
    time_t end_t = chrono::system_clock::to_time_t(end);//cast time object to time
    if(isSorted(arr, length[j])){
      cout<<"Tested BubbleSort on : "<<length[j]<<" values"<<endl;
      cout<<"Finished at "<<ctime(&end_t)<<" elapsed time "<<elapsed_seconds.count()<<"s"<<endl;
      cout<<swapCounter<<" swaps were done"<<endl;
    }else{
      cout<<"Not sorted"<<endl;
    }
    swapCounter=0;
    delete []  arr;
  }
  cout<<"============"<<endl;
}


cout<<endl;
cout<<"========+++++++++===========+++++++++++"<<endl;
cout<<endl;


for(int j=0;j<len;j++){
  for(int i=0;i<3;i++){
    arr=makeArray(length[j]);
    if(i==0){
      InspectionSort(arr, length[j]);
      cout<<"Desired array in ascending order: "<<endl;
    }else if(i==1){
      BackwardsSorter(arr, length[j]);
      cout<<"Desired array in decending order"<<endl;
    }else if(i==2){
      cout<<"Desired array is randomly order"<<endl;
    }
    auto start = chrono::system_clock::now();//stores current time

      InspectionSort(arr, length[j]);

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds =  end - start;
    time_t end_t = chrono::system_clock::to_time_t(end);//cast time object to time
    if(isSorted(arr, length[j])){
      cout<<"Tested InspectionSort on : "<<length[j]<<" values"<<endl;
      cout<<"Finished at "<<ctime(&end_t)<<" elapsed time "<<elapsed_seconds.count()<<"s"<<endl;
      cout<<swapCounter<<" swaps were done"<<endl;
    }else{
      cout<<"Not sorted"<<endl;
    }
    swapCounter=0;
    delete []  arr;
  }
  cout<<"============"<<endl;
}


cout<<endl;
cout<<"========+++++++++===========+++++++++++"<<endl;
cout<<endl;

for(int j=0;j<len;j++){
  for(int i=0;i<3;i++){
    arr=makeArray(length[j]);
    if(i==0){
      InspectionSort(arr, length[j]);
      cout<<"Desired array in ascending order: "<<endl;
    }else if(i==1){
      BackwardsSorter(arr, length[j]);
      cout<<"Desired array in decending order"<<endl;
    }else if(i==2){
      cout<<"Desired array is randomly order"<<endl;
    }
    auto start = chrono::system_clock::now();//stores current time

      SelectionSort(arr, length[j]);

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds =  end - start;
    time_t end_t = chrono::system_clock::to_time_t(end);//cast time object to time
    if(isSorted(arr, length[j])){
      cout<<"Tested Selection on : "<<length[j]<<" values"<<endl;
      cout<<"Finished at "<<ctime(&end_t)<<" elapsed time "<<elapsed_seconds.count()<<"s"<<endl;
      cout<<swapCounter<<" swaps were done"<<endl;
    }else{
      cout<<"Not sorted"<<endl;
    }
    swapCounter=0;
    delete []  arr;
  }
  cout<<"============"<<endl;
}
  return 0;
}
