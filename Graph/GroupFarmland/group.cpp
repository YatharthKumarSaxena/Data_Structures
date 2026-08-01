#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef pair<int, int> pip;

    pip findMaxRowMaxColOfFarm(vector<vector<int>>& land,
                               vector<vector<bool>>& visited,
                               int r, int c) {

        int m = land.size();
        int n = land[0].size();

        queue<pip> qu;
        qu.push({r, c});
        visited[r][c] = true;

        int maxR = r;
        int maxC = c;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        while (!qu.empty()) {
            pip curr = qu.front();
            qu.pop();

            int row = curr.first;
            int col = curr.second;

            maxR = max(maxR, row);
            maxC = max(maxC, col);

            for (int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (!visited[nr][nc] && land[nr][nc] == 1) {
                        visited[nr][nc] = true;
                        qu.push({nr, nc});
                    }
                }
            }
        }

        return {maxR, maxC};
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        int m = land.size();
        int n = land[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && land[i][j] == 1) {

                    pip rowCol = findMaxRowMaxColOfFarm(land, visited, i, j);

                    ans.push_back({i, j, rowCol.first, rowCol.second});
                }
            }
        }

        return ans;
    }
};