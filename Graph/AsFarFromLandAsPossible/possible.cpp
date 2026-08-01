#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxDisFromWaterSource(vector<vector<int>>& grid) {

        int maxDis = -1;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>, int>> qu;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    qu.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        while (!qu.empty()) {

            auto curr = qu.front();
            qu.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int dis = curr.second;

            if (grid[r][c] == 0) {
                maxDis = max(maxDis, dis);
            }

            for (int i = 0; i < 4; i++) {

                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    if (!visited[nr][nc] && !grid[nr][nc]) {
                        qu.push({{nr, nc}, dis + 1});
                        visited[nr][nc] = true;
                    }
                }
            }
        }

        return maxDis;
    }

    int maxDistance(vector<vector<int>>& grid) {
        return findMaxDisFromWaterSource(grid);
    }
};