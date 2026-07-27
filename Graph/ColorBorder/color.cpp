#include <vector>
using namespace std;

class Solution {
public:
    void colorCompleteComponent(vector<vector<int>>& grid, int row, int col,
                                int origColor, int newColor) {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m)
            return;
        else if (grid[row][col] == newColor)
            return;
        else if (grid[row][col] == origColor) {
            grid[row][col] = newColor;

            colorCompleteComponent(grid, row - 1, col, origColor, newColor);
            colorCompleteComponent(grid, row + 1, col, origColor, newColor);
            colorCompleteComponent(grid, row, col - 1, origColor, newColor);
            colorCompleteComponent(grid, row, col + 1, origColor, newColor);
        }
    }

    void uncolorUnboundaryComponent(vector<vector<int>>& origGrid,
                                    vector<vector<int>>& grid,
                                    vector<vector<bool>>& visited,
                                    int row, int col,
                                    int origColor, int newColor) {

        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m)
            return;
        else if (origGrid[row][col] != origColor)
            return;
        else if (grid[row][col] != newColor)
            return;

        if (visited[row][col])
            return;

        visited[row][col] = true;

        if (row > 0 && row < n - 1 && col > 0 && col < m - 1) {
            if (origGrid[row - 1][col] == origColor &&
                origGrid[row + 1][col] == origColor &&
                origGrid[row][col - 1] == origColor &&
                origGrid[row][col + 1] == origColor) {

                grid[row][col] = origColor;
            }
        }

        uncolorUnboundaryComponent(origGrid, grid, visited,
                                   row - 1, col, origColor, newColor);
        uncolorUnboundaryComponent(origGrid, grid, visited,
                                   row + 1, col, origColor, newColor);
        uncolorUnboundaryComponent(origGrid, grid, visited,
                                   row, col - 1, origColor, newColor);
        uncolorUnboundaryComponent(origGrid, grid, visited,
                                   row, col + 1, origColor, newColor);
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                    int row, int col, int color) {

        int origColor = grid[row][col];

        vector<vector<int>> origGrid = grid;

        colorCompleteComponent(grid, row, col, origColor, color);

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        uncolorUnboundaryComponent(origGrid, grid, visited,
                                   row, col, origColor, color);

        return grid;
    }
};