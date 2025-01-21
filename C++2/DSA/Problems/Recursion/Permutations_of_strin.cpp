// No. of total permutaions = n!('n' is the no. of characters in the string)
//                                                   i(index)
//                                                   |
//                                                  "abc"
//                                                /   |  \
//                                               /    |   \
//                              swap i wth i    /     |    \    swap i with i+2
//                                             /      |swap \
//                                         a  /       | i    \  c
//                                           /        |wiht   \
//                                          /         |i+1     \
//                                         /          |         \
//                                        /           | b        \
//                                       /            |           \
//                                      /             |            \
//                                 i   /             i|            i\
//                                 |  /              ||            | \
//                                abc               bac           cba
//              swap i with i----/ \-swap i with i+1/ \   swap i with i/  \swap i with i+1
//                            i /   \  i         i /   \            i /    \  i
//                            |/     \ |         |/     \           |/      \ |
//                          abc      acb       bac      bca       cba       cab
//                           | i      | i       | i      | i       | i       | i
//                           | |      | |       | |      | |       | |       | |
//                          abc      acb       bac      bca       cba       cab

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string str, int index, vector<string> &permutations)
{   //Base Case
    if (index>=str.length())
    {
        permutations.push_back(str);
        return;
    }
    
    for (size_t i = index; i < str.length(); i++)
    {
        swap(str[index],str[i]);
        solve(str,index+1,permutations);
        swap(str[index],str[i]);
    }
}

vector<string> permute(string str)
{
    vector<string> permutations;
    if (str.length() == 0)
    {
        return permutations;
    }

    int index = 0;
    solve(str, index, permutations);
    return permutations;
}
int main() {
    string input;
    cout << "Enter the  string: ";
    cin >> input;

    vector<string> result = permute(input);

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
