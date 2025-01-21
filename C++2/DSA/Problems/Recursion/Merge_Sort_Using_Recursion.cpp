//IMPORTANT HAI 

#include<iostream>

using namespace std;

void Merge(int *arr,int left_bound,int mid,int right_bound)
{
    int i = left_bound, j = mid + 1, k = 0;
    int temp[right_bound + 1];
    while (i<=mid && j<=right_bound)
    {
        if (arr[i]<arr[j])
        {
            temp[k] = arr[i];
            i++, k++; 
        }
        else{
            temp[k] = arr[j];
            j++, k++;
        }
    }
    while (i<=mid)
    {
        temp[k] = arr[i];
        i++, k++;
    }
    while (j<=right_bound)
    {
        temp[k] = arr[j];
        j++, k++;
    }
    k=0;
    for (int i = left_bound; i <= right_bound; i++)
    {
        arr[i] = temp[k];
        k++;
    }
}
void Merge_Sort(int *arr,int left_bound,int right_bound)
{   //Base Case
    if (left_bound >= right_bound) return;
    
    //Dividing array into two parts
    int mid = left_bound +(right_bound - left_bound)/2;

    //Recursively sorting two parts
    Merge_Sort(arr,left_bound,mid);
    Merge_Sort(arr,mid+1,right_bound);
    
    //Merging two parts in a sorted manner
    Merge(arr,left_bound,mid,right_bound);
    
}
int main()

{

  int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Merge_Sort(arr,0,n-1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}