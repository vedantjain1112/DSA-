#include<iostream>
using namespace std;

void merge2array(int arr1[], int arr2[], int size1, int size2, int res[]){
    int len1 = size1;
    int len2 = size2;
    int i = 0, j = 0, k = 0;
    while(i < len1 && j < len2){
        if(arr1[i] < arr2[j]){
            res[k] = arr1[i];
            i++;
            k++;
        }
        else{
            res[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i < len1){
        res[k] = arr1[i];
        k++;
        i++;
    }
    while(j < len2){
        res[k] = arr2[j];
        k++;
        j++;
    }
}

double median(int res[], int size){
    if(size % 2 == 0){
        int a = res[(size - 1) / 2];
        int b = res[((size - 1) / 2) + 1];
        double c = (a + b) / 2.0;
        return c;
    }
    else{
        int c = (size) / 2;
        return res[c];
    }
}

int main(){
    int size1;
    cout << "Enter the size of first array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter " << size1 << " elements in the first array: ";
    for(int i = 0; i < size1; i++){
        cin >> arr1[i];
    }
    int size2;
    cout << "Enter the size of second array: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter " << size2 << " elements in the second array: ";
    for(int i = 0; i < size2; i++){
        cin >> arr2[i];
    }
    
    int res[size1 + size2];
    merge2array(arr1, arr2, size1, size2, res);
    double ans = median(res, size1 + size2);
    cout << "Median of both the arrays is: " << ans << endl;
    return 0;
}

