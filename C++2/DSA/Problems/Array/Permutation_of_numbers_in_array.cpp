// No. of total permutaions = n!('n' is the no. of digits in the array or vector)
//                                                   i(index)
//                                                   |
//                                                  "1,2,3"
//                                                /   |  \
//                                               /    |   \
//                              swap i wth i    /     |    \    swap i with i+2
//                                             /      |swap \
//                                         1  /       | i    \  3
//                                           /        |wiht   \
//                                          /         |i+1     \
//                                         /          |         \
//                                        /           | 2        \
//                                       /            |           \
//                                      /             |            \
//                                 i   /             i|            i\
//                                 |  /              ||            | \
//                               1,2,3             2,1,3         3,2,1
//              swap i with i----/ \-swap i with i+1/ \   swap i with i/  \swap i with i+1
//                            i /   \  i         i /   \   i         i /    \  i
//                            |/     \ |         |/     \  |         |/      \ |
//                        1,2,3    1,3,2     2,1,3     2,3,1     3,2,1       312
//                           | i      | i       | i      | i       | i       | i
//                           | |      | |       | |      | |       | |       | |
//                        1,2,3    1,3,2     2,1,3    2,3,1     3,2,1     3,1,2

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> num, int index, vector<vector<int>> &permutations)
{ // Base Case
    if (index >= num.size())
    {
        permutations.push_back(num);
        return;
    }

    for (size_t i = index; i < num.size(); i++)
    {
        swap(num[index], num[i]);
        solve(num, index + 1, permutations);
        swap(num[index], num[i]);//Backtrack
    }
}

vector<vector<int>> permute(vector<int> num)
{
    vector<vector<int>> permutations;
    if (num.size() == 0)
    {
        return permutations;
    }

    int index = 0;
    solve(num, index, permutations);
    return permutations;
}
int main()
{
    vector<int> input = {1, 2, 3};

    vector<vector<int>> result = permute(input);

    // Print the results
    cout << '[';
    for (int j = 0; j < result.size(); j++)
    {
        cout << "{";
        for (int i = 0; i < result[j].size(); i++)
        {
            cout << result[j][i];
            if (i < result[j].size() - 1)
            {
                cout << ',';
            }
        }
        cout << "}";
    if (j < result.size() - 1)
    {
        cout << ',';
    }
    }
    cout << ']';
    return 0;
}