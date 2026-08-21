#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void doBacktrack(vector<vector<int>>& maze, vector<string>& ans,
                     int i, int j, string path) {
        
        int n = maze.size();

        if(i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }
        else if(i < 0 || i >= n || j < 0 || j >= n)
            return;
        else if(maze[i][j] == 0)
            return;
        else if(maze[i][j] == 2)
            return;

        maze[i][j] = 2;

        doBacktrack(maze, ans, i+1, j, path+'D');
        doBacktrack(maze, ans, i-1, j, path+'U');
        doBacktrack(maze, ans, i, j-1, path+'L');
        doBacktrack(maze, ans, i, j+1, path+'R');

        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();

        if(maze[n-1][n-1] == 0 || maze[0][0] == 0)
            return {};

        vector<string> ans;

        doBacktrack(maze, ans, 0, 0, "");

        sort(ans.begin(), ans.end());

        return ans;
    }
};