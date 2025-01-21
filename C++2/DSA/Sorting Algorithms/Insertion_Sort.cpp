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
    cout << "}"<<endl;
}

void Insertion_sort(int *array, int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
int main()

{
    int array[] = {1, 5, 3, 87, 9, 0, 3, 2, 5, 7, 12, 7};
    int n = sizeof(array) / sizeof(array[3]);
    
    print(array, n);

    Insertion_sort(array,n);
    print(array,n);
     return 0;
}