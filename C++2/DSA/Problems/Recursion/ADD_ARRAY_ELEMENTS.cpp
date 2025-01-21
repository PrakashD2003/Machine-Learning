// Q.Find Wheather a given array is sorted or not.

#include<iostream>

using namespace std;

int Add_Array(int *arr, int size) {
    // Base Case
    if (size == 0) {
        return 0;
    }

    // Recursive Case
    return arr[0] + Add_Array(arr + 1, size - 1);
}


#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = Add_Array(arr, size);
    cout<<"Sum of array elements:"<< sum;
    return 0;
}
