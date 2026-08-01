#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaxBombExplode(vector<vector<int>>& bombs,int i) {

        int n = bombs.size();
        int maxBombs = 0;

        queue<int> qu;
        vector<bool>visited(n);

        visited[i] = true;
        qu.push(i);

        while (!qu.empty()) {

            int idx = qu.front();
            qu.pop();
            maxBombs++;

            for(int j=0;j<n;j++){
                if(!visited[j]){
                    long long dx = 1LL * bombs[idx][0] - bombs[j][0];
                    long long dy = 1LL * bombs[idx][1] - bombs[j][1];
                    long long r = bombs[idx][2];

                    if (dx * dx + dy * dy <= r * r){
                        qu.push(j);
                        visited[j]=true;
                    }
                }
            }
        }

        return maxBombs;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int maxBombs = 1;
        int n = bombs.size();
        for(int i=0;i<n;i++){
            maxBombs = max(maxBombs,findMaxBombExplode(bombs,i));
        }
        return maxBombs;
    }
};