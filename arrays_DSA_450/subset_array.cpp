#include<iostream>
using namespace std;

int main(){
	
   int size1;
   cout<<"Enter the size for the first array: ";
   cin>>size1;
   cout<<endl;
   cout<<"Enter "<< size1 <<" elements in the array: ";
   int *arr1 = new int[size1];
   for(int i=0;i<size1;i++){
        cin>>arr1[i];
   }
   cout<<endl;
   int size2;
   cout<<"Enter the size of second array: ";
   cin>>size2;
   cout<<endl;
   cout<<"Enter "<< size2 <<" elements in the array: ";
   int *arr2 = new int[size2];
   for(int i=0;i<size2;i++){
        cin>>arr2[i];
   }
   cout<<endl;
   bool isSubset = true;
	
    for(int i=0;i<size2;i++){
        bool found = false;
        for(int j=0;j<size1;j++){
            if(arr2[i] == arr1[j]){
                found = true;
                break;
            }
        }
        if(!found){
            isSubset = false;
            break;
        }
    }
    if(isSubset){
        cout<<"B is a subset of A";
    }
    else{
        cout<<"B is not a subset of A";
    }
    
    delete[] arr1;
    delete[] arr2;
    
    return 0;
}

