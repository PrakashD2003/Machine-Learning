        //  mapping = {0-"",1- "",2- "abc",3- "def",4-"ghi",5- "jkl",6- "mno",7- "pqrs",8- "tuv",9- "wxyz"};                               
        //                                                   i(index) 
        //                                                   | 
        //                                                  "23"
        //                                                /   |  \
        //                                               /    |   \
        //                                              /     |    \
        //                                             /      |     \
        //                                            /       |      \
        //                                           /        |       \
        //                                          /         |        \
        //                                         /          |         \
        //                                        /           |          \
        //                                       /            |           \
        //                                      /             |            \
        //                                i    /            i |            i\
        //                                |   /             | |            | \
        //                               23,{a}-           23,{b}         23,{c}  
        //                               /|\                   /|\                / |\             
        //                      i       / | \            i    / | \              /  | \ 
        //                      |      /  |  \        |  |   /  |  \          | /|i |  \
        //                    23,{ad}  23,{ae} 23,{af}|23,{bd} 23,{be} 23,{bf}|23,{cd} 23,{ce} 23,{cf}
        //                         |        |       | |     |       |       | |     |       |       |
        //                       output   output  output  output  output  output  output  output  output 
        // The expression num[0] - '0' is a common technique in C++ (and C) to convert a character that represents a digit (e.g., '0', '1', '2', ...) into its corresponding integer value.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string digits, string output, int index, vector<string> &combinations,vector<string> mapping)
{   //Base Case
    if (index>=digits.length())
    {
        combinations.push_back(output);
        return;  
    }
    
    int num = digits[index] - '0'; // Convert char to int

    string letters = mapping[num]; // Get the letters for the current digit
    
    // Loop through each character in the letter
    for (size_t i = 0; i < letters.length(); i++)
    {                                                                                                 //order(Dry Run)
        output.push_back(letters[i]); //Push current character in the output                            a           ad          ae          b         further similar as a
        solve(digits,output,index+1,combinations,mapping); //Recursive call for next index              ad          d(remove)   e(remove)   bd
        output.pop_back();//Back tracking(emptying output for next character in the letters)            ad(push)    ae          af          bd(push)
                                                                                                      //            ae(push)    af(push)    
                                                                                                      //                        a(remove)
    }
    
    
}

vector<string> letterCombinations(string digits){
    vector<string> combinations;
    // Edge case: empty input
    if (digits.length()<=0)
    {
        return combinations;
    }
    
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    int index = 0;
    solve(digits,output,index,combinations,mapping);
    return combinations;
}



int main() {
    string input;
    cout << "Enter the digit string: ";
    cin >> input;

    vector<string> result = letterCombinations(input);

    // Print the results
    cout << '{';
    for (int j = 0; j < result.size(); j++)
    {
        cout << result[j];
        if (j < result.size() - 1)
        {
            cout << ',';
        }
    }
    cout << '}';

    return 0;
}
