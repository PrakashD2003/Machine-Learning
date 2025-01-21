// Find subsequences of the given string
// Number of elemenets in  set containing subsequences of string is = 2^n  ('n' is the number of character in the string)
// Example--  [abc]--[[],[a],[b],[c],[bc],[ac],[ab],[abc]]

//                    DRY RUN
//                                        index-- i
//                                                |
//                                 input array-- {abc}{}--output array
//                                                  / \  
//                                                 /   \   
//                                                /     \    
//                                    Exclude    /       \     Include
//                                      i       /         \      i
//                                      |      /           \     |
//                                    {abc}{}                  {abc}{a}
//                                    /\                               /\
//                                   /  \                             /  \
//                                  /    \                           /    \
//                                 /      \                         /      \ 
//                                /        \                       /        \
//                  Exclude      /          \  Include   Exclude  /          \   Include
//                       i      /            \  i          i     /            \   i
//                       |     /              \ |          |    /              \  |
//                    {abc}{}                {abc}{b}   {abc}{a}               {abc}{ab}
//                   /\                           /\            /\                    /\
//                  /  \                         /  \  Exclude /  \ Include  Exclude /  \  Include
//                 /    \                       /    \        /    \                /    \
//                /      \                     /      \      /      \          {abc}{ab}     {abc}{abc}
//               /        \                   /        \    /        \               |             |
//              /          \                 /          \ {abc}{a}  {abc}{ac}      output        output
//             /            \               /            \      |output    |
//            /              \     Exclude /              \ Include      output
//   Exclude /                \ Include   /                \  
//          /                  \         /                  \
//        {abc}{}         {abc}{c}  {abc}{b}       {abc}{bc}
//              |                         |               |
//           output                    output          output

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(string str, int index, string output, vector<string> &anw)
{
    // Base Case
    if (index >= str.length())
    {
        if (output.length() > 0)
        {

            anw.push_back(output);
        }
            return;
    }
    // Exclude
    solve(str, index + 1, output, anw);

    // Include
    char character = str[index];
    output.push_back(character);
    solve(str, index + 1, output, anw);
}

vector<string> Subsequences(string str)
{
    vector<string> anw;
    string output = "";
    int index = 0;
    solve(str, index, output, anw);
    return anw;
}

int main()
{
    string str = "abc";
    vector<string> anw = Subsequences(str);

    cout << '{';
    for (int j = 0; j < anw.size(); j++)
    {
        cout << anw[j];
        if (j < anw.size() - 1)
        {
            cout << ',';
        }
    }
    cout << '}';

    return 0;
}