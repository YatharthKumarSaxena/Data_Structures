#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int INF = INT_MAX;

        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);

            for (int j = start; j <= end; j++) {
                if (dp[j] != INF) {
                    dp[end] = min(dp[j] + 1, dp[end]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};