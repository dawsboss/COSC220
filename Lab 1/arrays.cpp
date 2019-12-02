#include  <iostream>


using namespace std;

double mean (int arr[], int length){//calulates means with brakets
	int sum=0;
	for(int i=0; i<length; i++){
		sum+=+arr[i];
	}
	cout<<sum;
	return sum/length;
}

double mean2 (int *arr, int length){//calulate the mean without brackets
	int sum=0;
	for(int i=0;i<length;i++){
		sum+=*(arr+i);
	}
	return sum/length;
}

int main(){
	int length=5;
	int input[5];
	for(int i=0; i<length; i++){//input
		cout<<"Input a number"<<endl;
		cin>>input[i];
	}
		cout<<"Your array is:"<< input[0];
	for(int i=1; i<length; i++){//output
		cout<<","<<input[i];
	}
	cout<<endl;
	cout<<"Your mean is (with brackets): "<<mean(input,length)<<endl;
	cout<<"Your mean is (without brackets): "<< mean2(input,length)<<endl;	
}
