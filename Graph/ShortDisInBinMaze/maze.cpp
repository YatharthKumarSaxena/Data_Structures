#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& mat, vector<int>& src, vector<int>& dest) {

        int m = mat.size();
        int n = mat[0].size();

        int sr = src[0];
        int sc = src[1];

        int fr = dest[0];
        int fc = dest[1];

        if (!(0 <= sr && sr < m && 0 <= sc && sc < n))
            return -1;

        if (!(0 <= fr && fr < m && 0 <= fc && fc < n))
            return -1;

        if (!mat[sr][sc] || !mat[fr][fc])
            return -1;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<pair<int,int>, int>> qu;
        qu.push({{sr, sc}, 0});
        visited[sr][sc] = true;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        while (!qu.empty()) {
            auto curr = qu.front();
            qu.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int dis = curr.second;

            if (r == fr && c == fc)
                return dis;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (!visited[nr][nc] && mat[nr][nc]) {
                        visited[nr][nc] = true;
                        qu.push({{nr, nc}, dis + 1});
                    }
                }
            }
        }

        return -1;
    }
};