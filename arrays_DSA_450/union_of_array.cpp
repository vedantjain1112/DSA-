#include<iostream>
#include<set>
using namespace std;

int main() {
    int size1;
    cout << "Enter the size of the first array: ";
    cin >> size1;

    int *a = new int[size1];
    cout << "Enter " << size1 << " elements in the first array: ";
    for (int i = 0; i < size1; i++) {
        cin >> a[i];
    }
    
    cout<<endl;
    int size2;
    cout << "Enter the size of the second array: ";
    cin >> size2;
    
	int *b = new int[size2];
    cout << "Enter " << size2 << " elements in the second array: ";
    for (int i = 0; i < size2; i++) {
        cin >> b[i];
    }

    set<int> s;
    for (int i = 0; i < size1; i++) {
        s.insert(a[i]);
    }

    for (int i = 0; i < size2; i++) {
        s.insert(b[i]);
    }
    
    cout<<endl;

    cout << "Union of both the two arrays is: ";
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    delete[] a;
    delete[] b;

    return 0;
}

