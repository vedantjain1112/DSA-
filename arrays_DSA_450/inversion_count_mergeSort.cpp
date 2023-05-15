#include<iostream>
using namespace std;

long long merge(int *arr,int start,int end){
    long long inv = 0;
    int mid = start + (end-start)/2;
    
    int len1 = mid-start+1;
    int len2 = end-mid;

    
    int *a = new int[len1];
    int *b = new int[len2];
    
    int k=start;
    
    for(int i=0;i<len1;i++){
        a[i] = arr[k];
        k++;
    }
    
    k = mid+1;
    for(int i=0;i<len2;i++){
        b[i] = arr[k];
        k++;
    }
    
    int i=0; 
    int j=0;
    k = start;
    while(i<len1 && j<len2){
        if(a[i]<=b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            //a[i]>b[j] and i<j;
            inv += len1-i;
            k++;
            j++;
        }
    }
    
    while(i<len1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j<len2){
        arr[k] = b[j];
        k++;
        j++;
    }
    
    delete[] a;
    delete[] b;
    
    return inv;
}



long long mergeSort(int *arr, int start,int end){
    long long inv = 0;
    if(start<end){
        int mid = start+(end-start)/2;
        inv += mergeSort(arr,start,mid);
        inv += mergeSort(arr,mid+1,end);
        inv += merge(arr,start,end);
    }
    return inv;
}


int main(){
	int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<endl;
    cout<<"Enter "<< size <<" elements in the array!";
    int *arr = new int[size];
    for(int i=0;i<size;i++){
    	cin>>arr[i];
	}
    int n = 8;
    int start=0;
    int end = size-1;
    cout<<endl;
    cout<<"Number of inversions in the array is/are:"<<mergeSort(arr,start,end);
    return 0;
}

