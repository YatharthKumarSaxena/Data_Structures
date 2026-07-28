#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> qu;

        // Convert to 0-based indexing
        knightPos[0]--;
        knightPos[1]--;
        targetPos[0]--;
        targetPos[1]--;

        if (knightPos == targetPos)
            return 0;

        qu.push({{knightPos[0], knightPos[1]}, 0});
        visited[knightPos[0]][knightPos[1]] = true;

        while (!qu.empty()) {
            auto curr = qu.front();
            qu.pop();

            int row = curr.first.first;
            int col = curr.first.second;
            int moves = curr.second;

            if (row == targetPos[0] && col == targetPos[1])
                return moves;

            if (row - 2 >= 0 && col - 1 >= 0 && !visited[row - 2][col - 1]) {
                visited[row - 2][col - 1] = true;
                qu.push({{row - 2, col - 1}, moves + 1});
            }

            if (row - 2 >= 0 && col + 1 < n && !visited[row - 2][col + 1]) {
                visited[row - 2][col + 1] = true;
                qu.push({{row - 2, col + 1}, moves + 1});
            }

            if (row + 2 < n && col - 1 >= 0 && !visited[row + 2][col - 1]) {
                visited[row + 2][col - 1] = true;
                qu.push({{row + 2, col - 1}, moves + 1});
            }

            if (row + 2 < n && col + 1 < n && !visited[row + 2][col + 1]) {
                visited[row + 2][col + 1] = true;
                qu.push({{row + 2, col + 1}, moves + 1});
            }

            if (row - 1 >= 0 && col - 2 >= 0 && !visited[row - 1][col - 2]) {
                visited[row - 1][col - 2] = true;
                qu.push({{row - 1, col - 2}, moves + 1});
            }

            if (row + 1 < n && col - 2 >= 0 && !visited[row + 1][col - 2]) {
                visited[row + 1][col - 2] = true;
                qu.push({{row + 1, col - 2}, moves + 1});
            }

            if (row - 1 >= 0 && col + 2 < n && !visited[row - 1][col + 2]) {
                visited[row - 1][col + 2] = true;
                qu.push({{row - 1, col + 2}, moves + 1});
            }

            if (row + 1 < n && col + 2 < n && !visited[row + 1][col + 2]) {
                visited[row + 1][col + 2] = true;
                qu.push({{row + 1, col + 2}, moves + 1});
            }
        }

        return -1;
    }
};