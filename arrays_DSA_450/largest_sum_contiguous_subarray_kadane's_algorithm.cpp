#include<iostream>
using namespace std;

int kadanesalgorithm(int *arr,int size){
	int sum=0;
	int maxi = arr[0];
	for(int i=0; i<size; i++){
		sum = sum + arr[i];
		maxi = max(maxi,sum);
		if(sum<0){
			sum = 0;
		}
	}
	return maxi;
}

int main(){
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	cout<<endl;
	cout<<"Enter "<< size <<" elements in the array: ";
	int *arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	int ans = kadanesalgorithm(arr,size);
	cout<<ans;
}

//-2 1 -3 4 -1 2 1 -5 4
//6