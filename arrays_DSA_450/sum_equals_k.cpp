#include<iostream>
#include<algorithm>
using namespace std;




int getPairsCount(int *arr, int size, int k) {
        sort(arr,arr+size);
        int count = 0;
        int i=0;
        int j=size-1;
        while(i<j){
            int currSum = arr[i]+arr[j];
            if(currSum = k){
                count++;
                j--;
                i++;
            }
            
            else if(currSum<k){
                i++;
            }
            
            else{
                j--;
            }
            
        
        }
    return count;
}

int main(){
	int size,k;
	cout<<"Enter size of the array : ";
	cin>>size;
	cout<<endl;
	cout<<"Enter the value of k : ";
	cin>>k;
	cout<<endl;
	cout<<"Enter "<<size<<" elements in the array : ";
	int *arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
   }
   cout<<endl;
   getPairsCount(arr,size,k);
}
    
    
    
