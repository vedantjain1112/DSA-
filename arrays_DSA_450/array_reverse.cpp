#include<iostream>
#include<math.h>
using namespace std;

void reverse(int *arr, int size,int m){
	int start = 0;
	int end = m;
	while(start<end){
		swap(arr[start],arr[end]);
		start++;
		end--;
    }
}
int main(){
	int size, m;
	cout<<"Enter the size of the array : ";
	cin>>size;
	cout<<endl;
	cout<<"Enter the value of m : ";
	cin>>m;
	cout<<endl;
	cout<<"Enter "<< size <<" elements : ";
	int *arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
    }
    reverse(arr,size,m);
    cout<<endl;
    cout<<"The reversed array is : ";
    for(int i=0;i<size;i++){
    	cout<<arr[i]<<" ";
	}
}
