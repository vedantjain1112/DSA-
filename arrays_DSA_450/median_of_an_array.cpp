#include<iostream>
#include<algorithm>
using namespace std;

int median(int *arr, int size){
	sort(arr,arr+size);
	if(size%2 == 0){
		int a  = arr[(size - 1) / 2];
        int b = arr[((size - 1) / 2) + 1];
        double c = (a + b) / 2.0;
        return c;
	}
	
	else{
		int c = (size) / 2;
        return arr[c];
	}
}

int main(){
	int size;
    cout << "Enter the size of first array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements in the first array: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int ans = median(arr,size);
    cout<<"The median of the array is : "<<ans;
}
