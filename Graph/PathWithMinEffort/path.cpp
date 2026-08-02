#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int,int>> State;

    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));

        priority_queue<State, vector<State>, greater<State>> pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int currEffort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            if (r == rows - 1 && c == cols - 1)
                return currEffort;

            if (currEffort > effort[r][c])
                continue;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                int edgeCost = abs(heights[r][c] - heights[nr][nc]);

                int newEffort = max(currEffort, edgeCost);

                if (newEffort < effort[nr][nc]) {

                    effort[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }

        return 0;
    }
};