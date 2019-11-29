#include <iostream>
#include <cmath>
using namespace std;

void selectionSort(int *&arr, int index);

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

    selectionSort(arr, index);
    for (int i = 0; i < index; i++)
    {
        cout << arr[i] << " ";
    }
}

void selectionSort(int *&arr, int index)
{
    for (int i = 0; i < index; i++)
    {
        int min = arr[i], indexOfSmallValue;

        for (int j = i; j < index; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                indexOfSmallValue = j;
            }
        }
        swap(arr[i], arr[indexOfSmallValue]);
    }
}
