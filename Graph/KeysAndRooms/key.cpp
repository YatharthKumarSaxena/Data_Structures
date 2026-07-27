#include <vector>
using namespace std;

class Solution {
public:
    void doDFS(vector<vector<int>>& rooms, vector<bool>& visited, int roomNum) {
        if (visited[roomNum])
            return;

        visited[roomNum] = true;

        for (int neighbour : rooms[roomNum]) {
            if (!visited[neighbour]) {
                doDFS(rooms, visited, neighbour);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0)
            return true;

        vector<bool> visited(n, false);

        doDFS(rooms, visited, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};