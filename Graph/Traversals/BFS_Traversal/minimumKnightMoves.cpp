#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int minimumKnightMoves(int x, int y) {
    if (x == 0 && y == 0) return 0;

    vector<pair<int, int>> dir = {{-1, -2}, {1, -2}, {-1, 2}, {-2, -1},
                                  {-2, 1}, {2, -1}, {1, 2}, {2, 1}};
    
    queue<tuple<int, int, int>> qu;
    qu.push(make_tuple(0, 0, 0)); // Start from (0,0) with 0 moves

    set<pair<int, int>> visited;
    visited.insert({0, 0});

    while (!qu.empty()) {
        auto [xCordinate, yCordinate, moves] = qu.front();
        qu.pop();

        for (auto [dx, dy] : dir) {
            int newRow = xCordinate + dx;
            int newCol = yCordinate + dy;

            if (newRow == x && newCol == y) return moves + 1;

            if (visited.count({newRow, newCol}) == 0) {
                visited.insert({newRow, newCol});
                qu.push(make_tuple(newRow, newCol, moves + 1));
            }
        }
    }
    return -1; // Should never reach here
}
