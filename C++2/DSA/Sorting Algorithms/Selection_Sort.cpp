#include <iostream>

using namespace std;

void print(int array[], int length)
{
    cout << "{";
    for (int i = 0; i < length; i++)
    {
        cout << array[i];
        if (i != length - 1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;
}

void Selection_Sort(int *array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    Selection_Sort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
