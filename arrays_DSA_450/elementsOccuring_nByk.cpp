#include <iostream>
#include <unordered_set>

using namepsace std;

void countElementsGreaterThanNByK(const int *arr, int size, int k) {
    unordered_set<int> elements(arr, arr + size);
    int threshold = size / k;

    cout << "Elements occurring more than " << threshold << " times:" << endl;
    for (int element : elements) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] == element) {
                count++;
            }
        }
        if (count > threshold) {
            cout << element << endl;
        }
    }
}

int main() {
    int size, k;
    cout << "Enter size of the array: ";
    cin >> size;
    cout << "Enter the value of k: ";
    cin >> k;

    int *arr = new int[size];
    cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    countElementsGreaterThanNByK(arr, size, k);
    delete[] arr;

    return 0;
}

