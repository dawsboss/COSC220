#include <iostream>
#include <stdlib.h>//rand
#include<time.h>//time
#include<chrono>//chrono

//using namespace std;

//swaps the two given varables values with one another
void swap(int &val1, int &val2){
  int tmp = val1;
  val1=val2;
  val2 = tmp;
}

//find thes the point we will quick sort off of
//<p | p | >p
//start inclusive, end exclusive
int partition(int arr[], int start, int end){
  int p = arr[end-1];
  int i=start-1;
  for(int j=start;j<end-1;j++){
    if(arr[j]<p){
      swap(arr[++i], arr[j]);
    }
  }
  swap(arr[++i], arr[end-1]);
  return i;
}

//used for backwardsQuickSort, and puts all points bigger than 'p' on thr rioght instead of left
int backwardsPartition(int arr[], int start, int end){
  int p = arr[end-1];
  int i=start-1;
  for(int j=start;j<end-1;j++){
    if(arr[j]>p){
      swap(arr[++i], arr[j]);
    }
  }
  swap(arr[++i], arr[end-1]);
  return i;
}

//actual quicksort algorithm
void quickSort(int arr[], int start, int end){
  if(start<end){
    int q = partition(arr, start, end);
    quickSort(arr, q+1, end);
    quickSort(arr, start, q);
  }

}

//sorts and array backwards (used for one of the test casses)
void backwardsQuickSort(int arr[], int start, int end){
  if(start<end){
    int q = backwardsPartition(arr, start, end);
    backwardsQuickSort(arr, q+1, end);
    backwardsQuickSort(arr, start, q);
  }

}

//makes an array with a given length and retuns a pointer ot it
int* makeArray(int len){
  int* rtn=new int[len];
  for(int i=0;i<len;i++){
    rtn[i]=1+rand()%100; //1-100
  }
  return rtn;
}

//prints a given array
void print(int* arr, int len){
  for(int i =0; i<len; i++){
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

//checks to see if the sort worked
bool isSorted(int* p,int len){
  for(int i=1;i<len;i++){
    if(p[i-1]>p[i]){
      return false;
    }
  }
  return true;
}

int main(){
  srand(time(NULL));
  int* arr = makeArray(10);
  print(arr, 10);
  int len=8;
  //all lengths that the arrays will be
  int length[]={1000,5000,10000,50000,100000,250000,500000,1000000};
  /*int p=partition(arr, 0, 10);BackwardsSorter
  std::cout<<p<<std::endl;
  print(arr, 10);*/


  for(int j=0;j<len;j++){
    for(int i=0;i<3;i++){
      arr=makeArray(length[j]);
      //depending on what iteration the array given to the timed quik sort will be acending, decending, and random given to the program.
      if(i==0){
        quickSort(arr,0, length[j]);
        std::cout<<"Desired array in ascending order: "<<std::endl;
      }else if(i==1){
        backwardsQuickSort(arr,0, length[j]);
        std::cout<<"Desired array in decending order"<<std::endl;
      }else if(i==2){
        std::cout<<"Desired array is randomly order"<<std::endl;
      }
      auto start = std::chrono::system_clock::now();//stores current time

        quickSort(arr, 0, length[j]);

      auto end = std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed_seconds =  end - start;
      time_t end_t = std::chrono::system_clock::to_time_t(end);//cast time object to time
      if(isSorted(arr, length[j])){
        std::cout<<"Tested quickSort on : "<<length[j]<<" values"<<std::endl;
        std::cout<<"Finished at "<<ctime(&end_t)<<" elapsed time "<<elapsed_seconds.count()<<"s"<<std::endl;

      }else{
        std::cout<<"Not sorted/error sorting"<<std::endl;
      }
      delete []  arr;
    }
    std::cout<<"============"<<std::endl;
  }




  return 0;
}
