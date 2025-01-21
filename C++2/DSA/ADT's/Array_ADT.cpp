#include <iostream>

using namespace std;

template <class T>
class static_array
{
private:
    T *nums;
    int total_size;
    int used_size = 0;

public:
    static_array(int Tsize) : total_size(Tsize)
    {
        nums = new T[Tsize];
    }
    ~static_array()
    {
        delete[] nums;
        cout << "Memory Freed" << endl;
    }

    void set(T *arr, int size)
    {
        if (used_size < total_size)
        {
            for (int i = 0; i < size; ++i)
            {
                nums[used_size] = arr[i];
                used_size++;
            }
        }
        else
        {
            cout << "Array is Full. Cannot append value." << endl;
        }
    }

    void insert(int index, T value)
    {
        if (index >= 0 && index < used_size)
        {
            if (used_size < total_size)
            {
                if (check_sort() == true)
                {
                    for (int i = used_size; i > index; i--)
                    {
                        nums[i] = nums[i - 1];
                    }
                }
                else
                {
                    nums[used_size] = nums[index];
                }
                nums[index] = value;
                used_size++;
            }
            else
            {
                throw runtime_error("Array is full. Cannot Insert value.");
            }
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }
    void deletetion(int index)
    {
        if (index >= 0 && index < used_size)
        {
            if (check_sort() == true)
            {
                for (int i = index; i < used_size - 1; i++)
                {
                    nums[i] = nums[i + 1];
                }
            }
            else
            {
                nums[index] = nums[used_size - 1];
            }
            used_size--;
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }
    T get(int index)
    {
        if (index >= 0 && index < used_size)
        {
            return nums[index];
        }
        else
        {
            throw out_of_range("Index out of range");
        }
    }
    void show()
    {
        cout << "[";
        for (int i = 0; i < used_size; i++)
        {
            if (i != used_size - 1)
            {
                cout << nums[i] << ",";
            }
            else
            {
                cout << nums[i];
            }
        }
        cout << "] " << "Used_Size = " << used_size << " Total_Size = " << total_size << endl;
    }

    int linearsearch(T key)
    {
        for (int i = 0; i < used_size; i++)
        {
            if (nums[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    int binarysearch(T key, int left_bound, int right_bound)
    {
        while (left_bound <= right_bound)
        {
            int mid = left_bound + (right_bound - left_bound) / 2;
            if (nums[mid] == key)
            {
                return mid;
            }
            if (nums[mid] < key)
            {
                left_bound = mid + 1;
            }
            else
            {
                right_bound = mid - 1;
            }
        }
        return -1;
    }
    
    int binarysearch(T key,int left_bound=0){
        return binarysearch(key,left_bound,used_size-1);
    }
    
    bool check_sort()
    {
        bool ascending = true;
        bool descending = true;

        for (int i = 0; i < used_size - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                ascending = false;
            }
            if (nums[i] < nums[i + 1])
            {
                descending = false;
            }
            if (!ascending && !descending)
            {
                return false; // Early exit
            }
        }

        return ascending || descending;
    }
};

int main()
{
    static_array<int> arr(10);
    int array[] = {1, 3, 4, 5, 8, 9, 10};
    arr.set(array, 7);
    cout<<arr.binarysearch(8)<<endl;
    arr.show();

    return 0;
}




