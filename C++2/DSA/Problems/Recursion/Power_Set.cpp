//Find power set of the given set in an array as input
//Number of elemenets in a power set = 2^n where 'n' is the number of elements in set
//Example-- Power set of [1,2,3] is--[[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
//                    DRY RUN
//                                        index-- i
//                                                |        
//                                 input array-- {1,2,3},{}--output array
//                                                 / \  
//                                                /   \   
//                                               /     \    
//                                   Exclude    /       \    Include
//                                     i       /         \    i
//                                     |      /           \   |               
//                                  {1,2,3},{}             {1,2,3},{1}
//                                  /\                               /\
//                                 /  \                             /  \
//                                /    \                           /    \
//                               /      \                         /      \ 
//                              /        \                       /        \
//                    Exclude  /          \  Include    Exclude /          \   Include
//                         i  /            \  i             i  /            \   i
//                         | /              \ |             | /              \  |
//                    {1,2,3},{}         {1,2,3},{2}   {1,2,3},{1}         {1,2,3},{1,2} 
//                    /\                           /\            /\                    /\
//                   /  \                         /  \  Exclude /  \ Include  Exclude /  \  Include
//                  /    \                       /    \        /    \                /    \
//                 /      \                     /      \      /      \   {1,2,3},{1,2}     {1,2,3},{1,2,3}
//                /        \                   /        \    /        \              |output             |
//               /          \                 /          \ {1,2,3},{1}  {1,2,3},{1,3}                  output
//              /            \               /            \          |              |
//             /              \     Exclude /              \ Include output        output 
//    Exclude /                \ Include   /                \  
//           /                  \         /                  \
// {1,2,3,},{}         {1,2,3},{3}  {1,2,3},{2}       {1,2,3},{2,3} 
//           |                   |            |                   | 
//        output               output       output              output

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> num,int index,vector<int> output,vector<vector<int>> &anw){
    //Base Case
    if (index >=num.size())
    {
        anw.push_back(output);
        return;
    }
    
    //Exclude
    solve(num,index + 1,output,anw);
    
    //Include
    int element = num[index];
    output.push_back(element);
    solve(num,index + 1,output,anw);  
}
 
vector<vector<int>> subsets(vector<int> num){
    vector<vector<int>> anw;
    vector<int> output;
    int i = 0;//Index
    solve(num,i,output,anw);
    return anw;
}

int main()
{
vector<int> array = {1,2,3};
vector<vector<int>> powerset = subsets(array);
cout<<'[';
for (int i = 0; i < powerset.size(); i++)
{   
    cout<<'{';
    for (int j = 0; j < powerset[i].size(); j++)
    {
        cout<<powerset[i][j];
        if (j< powerset[i].size()-1)
        {
            cout<<',';
        }
        

    }
    cout<<'}';
    if (i< powerset.size()-1)
        {
            cout<<',';
        }
}
    cout<<"]";

return 0;
}