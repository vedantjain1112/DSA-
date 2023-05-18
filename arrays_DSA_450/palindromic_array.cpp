#include<iostream>
using namespace std;

bool PalinArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
        int num = a[i];
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        if (rev != a[i]) {
            return false;
        }
    }
    return true;
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
    bool ans = PalinArray(arr,size);
    cout<< ans <<" the array is palindromic array! ";
}


//1 means true
//0 means false 
