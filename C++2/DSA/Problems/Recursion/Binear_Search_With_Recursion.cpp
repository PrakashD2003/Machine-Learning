// BINARY SEARCH WITH RECURSION
#include <iostream>

using namespace std;

int Binary_Search(int *arr, int left_bound, int right_bound, int key)
{
    int mid = left_bound + (right_bound - left_bound) / 2;
    // Base Case 1 Element Found
    if (left_bound > right_bound)
    {
        return -1;
    }
    // Base Case 2 Element Found
    if (arr[mid] == key)
    {
        return mid;
    }
    // Recursive Case
    else if (arr[mid] < key)
    {
        return Binary_Search(arr, left_bound = mid + 1, right_bound, key);
    }
    else
    {
        return Binary_Search(arr, left_bound, right_bound = mid - 1, key);
    }
}

int main()

{
    int array[] = {12, 3, 4, 5, 6, 65};
    int size = sizeof(array) / sizeof(array[0]);

    if ((Binary_Search(array, 0, size - 1, 5) == -1))
    {
        cout << "No Searched Element is Not Present in the Array." << endl;
    }
    else
    {
        cout << "Yes Searched Element is Present in the Array at index " << Binary_Search(array, 0, size - 1, 5) << endl;
    }

    return 0;
}









