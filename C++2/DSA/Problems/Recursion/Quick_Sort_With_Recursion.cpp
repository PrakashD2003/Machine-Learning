#include<iostream>
using namespace std;

int Partition(int*arr,int low,int high){
    int pivot = arr[low];
    int count = 0;
    //Counting the number of elements less than Pivot
    for (int i = low+1; i <= high; i++)
    {
        if (arr[i]<=pivot)
        {
            count++;
        }
    }

    int Pivot_Index = low + count;  
    //Place pivot in correct index 
    swap(arr[low],arr[Pivot_Index]);

    //Place all Elements smaller than Pivot to left og Pivot and all elements freater then pivot to right of pivot
    int i = low , j = high;
    while (i<Pivot_Index && j>Pivot_Index)
    {
    while (arr[i]<=pivot)
    {
        i++;
    }
    while (arr[j]>pivot)
    {
        j--;
    }
    if (i<Pivot_Index && j>Pivot_Index)
    {
        swap(arr[i++],arr[j--]);
    }
    }
    return Pivot_Index;
}

void Quick_Sort(int *arr,int low,int high){
    //Base Case
    if (low>=high) return;

    //Getting the Partition Index
    int partition = Partition(arr,low,high);

    //Recursive Case
    //Sorting Left Side 
    Quick_Sort(arr,low,partition-1);
    //Sorting Right Side 
    Quick_Sort(arr,partition+1,high);
}

int main()

{
 int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Quick_Sort(arr,0,n-1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}