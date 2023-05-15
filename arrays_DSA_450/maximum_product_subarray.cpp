#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
    long long prod = 1;
    long long int ans = INT_MIN;

    
    for (int i = 0; i < n; i++) {
        prod = prod * arr[i];
        ans = max(prod, ans);
        if (prod == 0) {
            prod = 1;
        }
    }

    prod = 1; 

    
    for (int i = n - 1; i >= 0; i--) {
        prod = prod * arr[i];
        ans = max(prod, ans);
        if (prod == 0) {
            prod = 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout<<endl;
    cout << "Enter " << n << " elements in the array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout<<endl;

    long long maxProd = maxProduct(arr, n);
    cout << "Maximum product of subarray: " << maxProd << endl;

    return 0;
}

