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
int Partition(int *array, int low, int high)
{
    int pivot = low;
    int i = low + 1;
    int j = high;

    do
    {
        while (array[i] <= array[pivot])
        {
            i++;
        }
        while (array[j] > array[pivot])
        {
            j--;
        }

        if (i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while (i < j);

    int temp2 = array[low];
    array[low] = array[j];
    array[j] = temp2;
    return j;
}

void Quick_Sort(int *array, int low, int high)
{
    if (low<high)
    {
        int partitionIndex = Partition(array, low, high);

        Quick_Sort(array, low, partitionIndex - 1);
        Quick_Sort(array, partitionIndex + 1, high);
    }
}

int main()

{
    int array[] = {1, 5, 3, 87, 9, 0, 3, 2, 5, 7, 12, 7};
    int n = sizeof(array) / sizeof(array[3]);

    print(array, n);

    Quick_Sort(array, 0, n - 1);
    print(array, n);
    return 0;
}