#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int size, i;
    cout<<"Enter size: ";
    cin >> size;
    cout<<endl;
    int *arr = new int[size];
	int j = size - 1;
    cout <<"Enter "<< size <<" elements:";
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout<<endl;
    while (true)
    {
        i = 0;
        while (arr[i] < 0 && i < j)
            i++;
        while (arr[j] > 0 && i < j)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }
    
    cout<<"The array of arranged negative and positive numbers are: ";
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}




































