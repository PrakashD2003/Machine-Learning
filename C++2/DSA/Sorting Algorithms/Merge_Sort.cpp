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
void Merge(int array1[], int n, int array2[], int m, int result[]) // n and m are sizes of array1 and array2
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (array1[i] < array2[j])
        {
            result[k] = array1[i];
            i++, k++;
        }
        else
        {
            result[k] = array2[j];
            j++, k++;
        }
    }
    while (i < n)
    {
        result[k] = array1[i];
        i++, k++;
    }

    while (j < m)
    {
        result[k] = array2[j];
        j++, k++;
    }
}
void Merge_Single_Array(int array[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int result[high + 1];
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            result[k] = array[i];
            i++, k++;
        }
        else
        {
            result[k] = array[j];
            j++, k++;
        }
    }
    while (i <= mid)
    {
        result[k] = array[i];
        i++, k++;
    }

    while (j <= high)
    {
        result[k] = array[j];
        j++, k++;
    }
    k = 0;
    for ( i = low; i <= high; i++)
    {
        array[i] = result[k];
        k++;
    }
}
void Merge_Sort(int array[], int low, int high)
{
    if (low<high)
        {
            int mid = low + (high - low) / 2;

            Merge_Sort(array,low,mid);
            Merge_Sort(array,mid+1,high);

            Merge_Single_Array(array,low,mid,high);
        }
}

int main()

{
    int array1A[] = {1, 2, 3, 4, 5};
    int array2A[] = {6, 7, 8, 9, 10};
    int array3A[10];

    Merge(array1A, 5, array2A, 5, array3A);
    print(array3A, 10);

    int array1B[] = {10, 11, 12, 1, 2, 3};

    Merge_Single_Array(array1B, 0, 2, 5);
    print(array1B, 6);
    
    int arrayC[] = {1,4,43,7,4,34,3,34,34,23,5,6,4,5,2,67,9,5,3};
    Merge_Sort(arrayC,0,18);
    print(arrayC,19);
    return 0;
}