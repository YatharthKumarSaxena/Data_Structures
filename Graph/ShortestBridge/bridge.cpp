#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void doDFSInComp(vector<vector<int>>& grid, int r, int c, int color, int newColor) {
        int n = grid.size();

        if (r < 0 || c < 0 || r >= n || c >= n)
            return;
        else if (grid[r][c] == newColor)
            return;
        else if (grid[r][c] != color)
            return;
        else {
            grid[r][c] = newColor;

            doDFSInComp(grid, r - 1, c, color, newColor);
            doDFSInComp(grid, r, c - 1, color, newColor);
            doDFSInComp(grid, r + 1, c, color, newColor);
            doDFSInComp(grid, r, c + 1, color, newColor);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        bool isFound = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    doDFSInComp(grid, i, j, grid[i][j], -1);
                    isFound = true;
                    break;
                }
            }
            if (isFound)
                break;
        }

        queue<pair<pair<int, int>, int>> qu;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1)
                    qu.push({{i, j}, 0});
            }
        }

        while (!qu.empty()) {
            auto curr = qu.front();
            qu.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int level = curr.second;

            if (r > 0) {
                if (grid[r - 1][c] == 1)
                    return level;
                else if (grid[r - 1][c] == 0) {
                    grid[r - 1][c] = -1;
                    qu.push({{r - 1, c}, level + 1});
                }
            }

            if (c > 0) {
                if (grid[r][c - 1] == 1)
                    return level;
                else if (grid[r][c - 1] == 0) {
                    grid[r][c - 1] = -1;
                    qu.push({{r, c - 1}, level + 1});
                }
            }

            if (r < n - 1) {
                if (grid[r + 1][c] == 1)
                    return level;
                else if (grid[r + 1][c] == 0) {
                    grid[r + 1][c] = -1;
                    qu.push({{r + 1, c}, level + 1});
                }
            }

            if (c < n - 1) {
                if (grid[r][c + 1] == 1)
                    return level;
                else if (grid[r][c + 1] == 0) {
                    grid[r][c + 1] = -1;
                    qu.push({{r, c + 1}, level + 1});
                }
            }
        }

        return 0;
    }
};