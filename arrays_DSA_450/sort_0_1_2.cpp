#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter the size of the array : ";
	cin>>size;
	cout<<"Enter the elements in the array : ";
	int *arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	int zeroCount = 0;
	int oneCount = 0;
	int twoCount = 0;
	
	for(int i=0;i<size;i++){
		if(arr[i]==0){
			zeroCount++;
		}
		else if(arr[i]==1){
			oneCount++;
		}
		else{
			twoCount++;
		}
	}
	
	int i=0;
	for(int j=0;j<zeroCount;j++){
		arr[i] = 0;
		i++;
	}
	
	for(int j=0;j<oneCount;j++){
		arr[i] = 1;
		i++;
	}
	
	for(int j=0;j<twoCount;j++){
		arr[i] = 2;
		i++;
	}
	cout<<endl;
	cout<<"Rearranged array is: "<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}

