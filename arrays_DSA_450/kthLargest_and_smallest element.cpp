#include<iostream>
#include<algorithm>
using namespace std;

void kthsmallest(int *arr, int size, int k){
	sort(arr,arr+size);
	cout<< k <<"th smallest element in the array is: "<<arr[k-1]<<" "<<endl;
	cout<<endl;
}

void kthlargest(int *arr, int size, int k){
	sort(arr,arr+size);
	cout<< k <<"th largest element in the array is: "<<arr[size-k]<<" "<<endl;
	cout<<endl;
}

int main(){
	int size,k;
	cout<<"Enter the size of the array: ";
	cin>>size;
	cout<<endl;
	cout<<"Enter the value of k:";
	cin>>k;
	cout<<endl;
	int *arr = new int[size];
	cout<<"Enter "<< size <<" elements in the array: ";
	int i=0;
	for(;i<size;i++){
		cin>>arr[i];
	}
	cout<<endl;
	kthsmallest(arr,size,k);
	kthlargest(arr,size,k);
	return 0;
}
