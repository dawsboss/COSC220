//Grant Dawson, COSC 220
#include <iostream>

using namespace std;

//adds a space in a given dyamin array and adds a new space and value to the end.
int* addSpace(int length, int *arr, int val){
  int *temp=new int[length+1];//holds values of orginal array
  for(int i=0;i<length;i++){
    temp[i]=arr[i];
  }
  for(int i=0;i<length;i++){
    cout<<"arr "<<arr[i]<<" "<<"temp "<<temp[i]<<" ";
    cout<<endl;
  }
  cout<<temp[length-1]<<endl;
  delete [] arr;
  
  temp[length]=val;
  return temp;
}

int main(){
  int size=1;//Init size of the dyanmic array
  int *arr1=new int[size];//delcare the dynamic array
  bool stop=true;
  int input;
  cout<<"Input as many numbers as you want but, to stop put in 0(zero)."<<endl;
  for(int i=0;stop; i++){
    cout<<"Input a number: "<<endl;
    cin>>input;
    if(input==0){
      stop=false;
      size--;
    }else if(size==1){
      arr1[0]=input;
      size++;
    }else{
      arr1=addSpace(size-1,arr1,input);
      size++;
    }
  }
  cout<<"size = "<<size<<endl;
  cout<<"Your final array is: ";
  cout<< "test"<<arr1[0];
  for(int i=1; i<size; i++){
    cout<<", "<<arr1[i];
  }
  cout<<endl;

}
