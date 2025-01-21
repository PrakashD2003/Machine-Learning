// Q.Find Wheather a given array is sorted or not.

#include<iostream>

using namespace std;

bool is_Sorted(int *arr,int size){
    //Base Case
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0]>arr[1])
    {
        return false;
    }
    else{
        //Recursive Case
        return is_Sorted(arr+1,size-1);
    }
}
int main()

{
 int array[10] = {1,2,3,4,5,6,7,8,9,10};
 if (is_Sorted(array,10)==true)
 {
    cout<<"Array is Sorted.";
 }
 else{
    cout<<"Array is not Sorted.";

 }
return 0;
}