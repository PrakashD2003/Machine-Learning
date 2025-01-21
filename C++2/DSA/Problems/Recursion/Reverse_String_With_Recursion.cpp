// Reverse the given string example- abcd = dcba

#include <iostream>
#include <string>
using namespace std;

void reverse_string(string &input, int left_bound, int right_bound)
{
    int i = left_bound, j = right_bound;
    //Base Case
    if (i >= j)
    {
        return;
    }
    //Swap the first and last character
    char temp = input[j];
    input[j] = input[i];
    input[i] = temp;
    //Recursive Case(increment pointers to swap second and second last element)
    return reverse_string(input, i + 1, j - 1);
}
int main()
{
    string one = "abcd";
    reverse_string(one, 0, one.length() - 1);
    cout << one << endl;

    return 0;
}