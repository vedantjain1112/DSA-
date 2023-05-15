#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout <<endl;

    int* arr = new int[size];
    std::cout << "Enter " << size << " elements in the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> negatives;
    vector<int> positives;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            negatives.push_back(arr[i]);
        } else {
            positives.push_back(arr[i]);
        }
    }

    int negIndex = 0;
    int posIndex = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0 && negIndex < negatives.size()) {
            arr[i] = negatives[negIndex];
            negIndex++;
        } else if (posIndex < positives.size()) {
            arr[i] = std::abs(positives[posIndex]);
            posIndex++;
        }
    }

    cout<<endl;
    cout << "Rearranged array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}

