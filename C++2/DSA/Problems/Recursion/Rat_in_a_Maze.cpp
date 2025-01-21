// Q.Consider a rat placed at (0, 0) in a square matrix of order N * N.
// It has to reach the destination at (N - 1, N - 1).
// Find all possible paths that the rat can take to reach from source to destination.
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
// Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it
// while value 1 at a cell in the matrix represents that rat can travel through it.

// Note: In a path, no cell can be visited more than one time.

// Print the answer in lexicographical(sorted) order

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}}

// Output: DDRDRR DRDDRR

// Explanation:
// The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR,
// when printed in sorted order we get DDRDRR DRDDRR.

//**MAZE**
//  
// X|  Y  0     1    2    3
//  |------------------------
// 0|     1     0    0    0
//  |
// 1|     1     1    0    1
//  |
// 2|     1     1    0    0
//  |
// 3|     0     1    1    1


//**Movements
// Up(X-1,Y)
// Down(X+1,Y)
// Right(X,Y+1)
// Left(X,Y-1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(vector<vector<int>> &maze, vector<vector<int>> visited, int n, int x, int y)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &maze, int n, string path, int x, int y, vector<vector<int>> visited, vector<string> &Total_paths)
{ // Reached  (x,y)
    // Base Case
    if (x == n - 1 && y == n - 1)
    {
        Total_paths.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Now we have 4 choices to mive Up down left right
    // Down
    int new_x = x+1;
    int new_y = y;
    if (isSafe(maze,visited,n,new_x,new_y))
    {
        path.push_back('D');
        solve(maze, n, path, new_x, new_y, visited, Total_paths);
        path.pop_back(); // Backtrace
    }
    // Right
     new_x = x;
     new_y = y+1;
    if (isSafe(maze,visited,n,new_x,new_y))
    {
        path.push_back('R');
        solve(maze, n, path, new_x, new_y, visited, Total_paths);
        path.pop_back(); // Backtrace
    }
    // Left
     new_x = x;
     new_y = y-1;
    if (isSafe(maze,visited,n,new_x,new_y))
    {
        path.push_back('L');
        solve(maze, n, path, new_x, new_y, visited, Total_paths);
        path.pop_back(); // Backtrace
    }
    // Up
     new_x = x-1;
     new_y = y;
    if (isSafe(maze,visited,n,new_x,new_y))
    {
        path.push_back('U');
        solve(maze, n, path, new_x, new_y, visited, Total_paths);
        path.pop_back(); // Backtrace
    }
    visited[x][y] = 0;
}

vector<string> findpath(vector<vector<int>> &maze, int n)
{
    vector<string> Total_paths;
    if (maze[0][0] == 0)
    {
        return Total_paths;
    }
    int srcX = 0;
    int srcY = 0;

    vector<vector<int>> visited = maze;
    // Initialize visited to 0
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(maze, n, path, srcX, srcY, visited, Total_paths);
    sort(Total_paths.begin(), Total_paths.end());
    return Total_paths;
}
int main() {
    // Sample maze
    vector<vector<int>> maze = {
      {{1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}}
    };

    int n = maze.size(); // Dimension of the maze

    // Call the findpath function
    vector<string> paths = findpath(maze, n);

    // Print the paths
    if (paths.empty()) {
        cout << "No path found from source to destination." << endl;
    } else {
        cout << "Paths from source to destination:" << endl;
        for (const string &path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}