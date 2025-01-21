#include <iostream>

using namespace std;

void Bubble_Sort(int *array, int n)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        return;
    }
    //ye for loop ek largest element ko end me pohuncha dega to hamne ek case solve kar diya baaki recursion dekh lega
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            swap(array[i], array[i + 1]);
        }
    }
    //Recursive Case
    return Bubble_Sort(array, n - 1);
}
int main()

{
    int array[5] = {5,4,3,2,1};
    Bubble_Sort(array, 5);
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}