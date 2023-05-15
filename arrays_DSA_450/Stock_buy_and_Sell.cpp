#include<iostream>
#include<math.h>
using namespace std;

int stocks(int *sellingPrice,int size){
	int buyPrice = INT_MAX;   //+infinity se initialize krdo 
	int maxProfit = 0; 
	for(int i=0;i<size;i++){
		if(buyPrice < sellingPrice[i]){
			int profit = sellingPrice[i] - buyPrice;
		    maxProfit = max(maxProfit,profit);
		}
	    else{
	        buyPrice = sellingPrice[i];
	    }
   } 
	return maxProfit;
}

int main(){
	int size;
	cout<<"Enter the size of the arrray: ";
	cin>>size;
	cout<<endl;
	cout<<"Enter "<< size <<" elements in the array: ";
	int *sellingPrice = new int[size];
	for(int i=0;i<size;i++){
		cin>>sellingPrice[i];
	}
	int ans = stocks(sellingPrice,size);
	cout<<endl;
	cout<<"The maximum profit you can get is Rs."<<ans;
}
//7 1 5 3 6 4
//5 -->ans
