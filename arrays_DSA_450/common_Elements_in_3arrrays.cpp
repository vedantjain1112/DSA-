#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> commonElements(int *arr1, int *arr2, int *arr3, int n1, int n2, int n3) {
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> ans;
    set<int> s;
    while (i < n1 && j < n2 && k < n3) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            s.insert(arr1[i]);
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }
    for (auto num : s) {
        ans.push_back(num);
    }
    return ans;
}

int main() {
    int size1, size2, size3;
    cout << "Enter the size of the array: ";
    cin >> size1;
    cout << endl;
    cout << "Enter " << size1 << " elements in the array: ";
    int *arr1 = new int[size1];
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the array: ";
    cin >> size2;
    cout << endl;
    cout << "Enter " << size2 << " elements in the array: ";
    int *arr2 = new int[size2];
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    cout << "Enter the size of the array: ";
    cin >> size3;
    cout << endl;
    cout << "Enter " << size3 << " elements in the array: ";
    int *arr3 = new int[size3];
    for (int i = 0; i < size3; i++) {
        cin >> arr3[i];
    }
    cout << endl;
    cout << "Common elements in three arrays are: ";
    vector<int> result = commonElements(arr1, arr2, arr3, size1, size2, size3);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}

