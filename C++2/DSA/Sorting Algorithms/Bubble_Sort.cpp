#include <iostream>

using namespace std;

void print(int array[], int n)
{
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i != n - 1)
        {
            cout << ",";
        }
    }
    cout << "}";
}

void Bubble_Sort(int *array, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void Addaptive_Bubble_Sort(int *array, int n)
{
    int sorted = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted = 1)
            return;
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    Bubble_Sort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
