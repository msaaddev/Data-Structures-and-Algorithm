#include <iostream>
#include <cmath>
using namespace std;

void bubbleSort(int *&arr, int index);
int binarySearch(int value, int *&arr, int index);

int main()
{
    int index, search;

    cout << "Enter the size of the array: ";
    cin >> index;

    int *arr = new int[index];

    for (int i = 0; i < index; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, index);
    for (int i = 0; i < index; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nEnter value which needs to be searched: ";
    cin >> search;

    int result = binarySearch(search, arr, index);
    if (result == -1)
        cout << "Value does not exist. ";
    else
        cout << result;

    delete[] arr;
}

void bubbleSort(int *&arr, int index)
{
    for (int i = 0; i < index - 1; i++)
        for (int j = 0; j < index - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int binarySearch(int value, int *&arr, int index)
{

    int mid, low, high;
    low = 0;
    high = index - 1;
    mid = (low + high) / 2;

    while (mid >= 0)
    {
        if (value == arr[mid])
        {
            return mid;
        }
        if (value > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
        if (low > high)
            return -1;

        mid = (low + high) / 2;
    }

    return -1;
}
