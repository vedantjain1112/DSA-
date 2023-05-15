#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	cout<<"Enter "<< size <<" elements in the array: ";
	int *arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	int k;
	cout<<"Enter the value of k: ";
	cin>>k;
	int temp[size] = {0};
	for(int i=0;i<size;i++){
		temp[(i+k)%size] = arr[i]; 
	}
	cout<<"Rotated array is: ";
	for(int i=0;i<size;i++){
		cout<<temp[i]<<" ";
	}
}
           
