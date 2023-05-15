#include<iostream>
using namespace std;

int maximum(int *arr, int size){
	int maxi = arr[0];
	for(int i=0;i<size;i++){
		if(arr[i]>maxi){
			maxi = arr[i];
		}
	}
	return maxi;
}

int minimum(int *arr, int size){
	int mini = arr[0];
	for(int i=0;i<size;i++){
	    if(arr[i]<mini){
			mini = arr[i];
		}
	}
	return mini;
}

void dispArray(int *arr, int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}


int main(){
	int size,m;
	cout<<"Enter size of the array : ";
	cin>>size;
	cout<<endl;
	cout<<"Enter "<<size<<" elements in the array : ";
	int *arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
   }
   cout<<endl;
   int _max = maximum(arr,size);
   int _min = minimum(arr,size);
   cout<<"Array you entered is : ";
   dispArray(arr,size);
   cout<<endl;
   cout<<"Maximum element in the array is : "<<_max<<" ";
   cout<<endl;
   cout<<"Minimum element in the array is : "<<_min<<" ";
}
//1 3 4 7 9 9 12 56  
