#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTotalNodeInConnComp(int sr, int sc,
                                vector<vector<int>>& image,
                                vector<vector<bool>>& visited) {

        int m = image.size();
        int n = image[0].size();

        queue<vector<int>> qu;
        qu.push({sr, sc});
        visited[sr][sc] = true;

        int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
        int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

        int totalNodes = 1;

        while (!qu.empty()) {
            auto curr = qu.front();
            qu.pop();

            int r = curr[0];
            int c = curr[1];

            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (!visited[nr][nc] && image[nr][nc]) {
                        qu.push({nr, nc});
                        visited[nr][nc] = true;
                        totalNodes++;
                    }
                }
            }
        }

        return totalNodes;
    }

    int findMaxArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int maxNodes = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j]) {
                    maxNodes = max(maxNodes,
                                   findTotalNodeInConnComp(i, j, grid, visited));
                }
            }
        }

        return maxNodes;
    }
};