#include <iostream>
using namespace std;

// Function to insert the last element of the current array into its correct position
void insert(int arr[], int n) {
    int key = arr[n - 1];
    int j = n - 2;

    // Shift elements of the sorted portion to the right to make space for the key
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

// Recursive function to sort the array
void insertionSortRec(int arr[], int n) {
    // Base case: If the array size is 1 or less, it's already sorted
    if (n <= 1) return;

    // Sort the first n-1 elements recursively
    insertionSortRec(arr, n - 1);

    // Insert the nth element into its correct position
    insert(arr, n);
}

// Driver code to test the function
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSortRec(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
