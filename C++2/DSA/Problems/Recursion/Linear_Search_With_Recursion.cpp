//LINEAR SEARCH WITH RECURSION
#include <iostream>

using namespace std;

bool linear_search(int *arr, int size, int key)
{
    // Base Case
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
        return linear_search(arr + 1, size - 1, key);
}
int main()

{
    int array[] = {12,3,4,5,6,65};
    int size = sizeof(array)/sizeof(array[0]);

    if (linear_search(array,size,55)==true)
    {
        cout<<"Yes Search Element is Present in the Array."<<endl;
    }
    else{
        cout<<"No Search Element is Not Present in the Array."<<endl;

    }
    

    return 0;
}