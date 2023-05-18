#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trappedRainWater(int *arr, int size) {
    if (size <= 2) {
        return 0;
    }

    int ans = 0;
    vector<int> A(size);
    vector<int> B(size);

    A[0] = arr[0];
    for (int i = 1; i < size; i++) {
        A[i] = max(A[i - 1], arr[i]);
    }

    B[size - 1] = arr[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        B[i] = max(B[i + 1], arr[i]);
    }

    for (int i = 0; i < size; i++) {
        int trappedWater = min(A[i], B[i]) - arr[i];
        if (trappedWater > 0) {
            ans += trappedWater;
        }
    }

    return ans;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int trappedWater = trappedRainWater(arr, size);
    cout << "Trapped Rainwater is: " << trappedWater << endl;

    return 0;
}


//i/p : 4, 2, 0, 6, 3, 2, 5
//o/p : 11

