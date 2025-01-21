#include<iostream>

using namespace std;

int Max_Element(int *arr,int size)
{
    int max_element = arr[0];
    
        for (int i = 1; i < size; i++)
        {
            if (arr[i]>max_element)
            {
                max_element = arr[i];
            }
            
        }
    
    return max_element; 
}

int main()

{
 int array[5] = {6,45,300,34,100};
 int size = sizeof(array)/sizeof(array[0]);
 cout<<Max_Element(array,size);

return 0;
}