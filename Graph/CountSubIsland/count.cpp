#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    typedef pair<int, int> pip;

    bool checkSubIsland(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2,
                        vector<vector<bool>>& visited,
                        int r, int c) {

        int m = grid1.size();
        int n = grid1[0].size();

        queue<pip> qu;
        qu.push({r, c});
        visited[r][c] = true;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        bool isSubIsland = true;

        while (!qu.empty()) {
            pip curr = qu.front();
            qu.pop();

            int row = curr.first;
            int col = curr.second;

            if (grid1[row][col] == 0)
                isSubIsland = false;

            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (!visited[nr][nc] && grid2[nr][nc] == 1) {
                        visited[nr][nc] = true;
                        qu.push({nr, nc});
                    }
                }
            }
        }

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {

        int m = grid1.size();
        int n = grid1[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid2[i][j] == 1) {
                    if (checkSubIsland(grid1, grid2, visited, i, j))
                        ans++;
                }
            }
        }

        return ans;
    }
};