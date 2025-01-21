// A string is called a palindrome if the string and its reversed string is same example-- abba

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool Check_Palindrome_Rec(string input, int left_bound, int right_bound)
{

    // Base Case
    if (left_bound > right_bound)
    {
        return true;
    }
    if (input[left_bound] != input[right_bound])
    {
        return false;
    }
    return Check_Palindrome_Rec(input, left_bound + 1, right_bound - 1);
}
bool Check_Palindrome(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (!isalnum(input[i]))
        {
            input.erase(i, 1);
            i--; // Adjust the index after erasing a character
        }
    }
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return Check_Palindrome_Rec(input, 0, input.length() - 1);
}
int main()

{
    string one = "1a";
    if (Check_Palindrome(one) == true)
    {
        cout << "Yes Given String \"" << one << "\" is a palindrome." << endl;
    }
    else
    {
        cout << "No Given String \"" << one << "\" is Not a palindrome." << endl;
    }

    cout << one << endl;

    return 0;
}