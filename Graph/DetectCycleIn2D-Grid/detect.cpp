#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCycleByBFS(vector<vector<char>>& grid,
                          vector<vector<bool>>& visited,
                          int r, int c,
                          vector<vector<pair<int,int>>>& parent) {

        int m = grid.size();
        int n = grid[0].size();

        char color = grid[r][c];

        queue<pair<int,int>> qu;
        qu.push({r, c});
        visited[r][c] = true;

        vector<pair<int,int>> directions = {
            {-1, 0},  // Up
            {1, 0},   // Down
            {0, -1},  // Left
            {0, 1}    // Right
        };

        while (!qu.empty()) {
            auto [row, col] = qu.front();
            qu.pop();

            for (auto [dx, dy] : directions) {
                int newX = row + dx;
                int newY = col + dy;

                if (newX >= 0 && newX < m &&
                    newY >= 0 && newY < n &&
                    grid[newX][newY] == color) {

                    if (visited[newX][newY] &&
                        parent[row][col] != make_pair(newX, newY)) {
                        return true;
                    }
                    else if (!visited[newX][newY]) {
                        qu.push({newX, newY});
                        visited[newX][newY] = true;
                        parent[newX][newY] = {row, col};
                    }
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<pair<int,int>>> parent(
            m, vector<pair<int,int>>(n, {-1, -1})
        );

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (detectCycleByBFS(grid, visited, i, j, parent))
                        return true;
                }
            }
        }

        return false;
    }
};