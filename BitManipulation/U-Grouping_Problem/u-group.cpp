#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dp[1 << 16];
    long long groupScore[1 << 16];

    long long solve(int mask, int n) {
        if (mask == (1 << n) - 1)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];

        long long ans = LLONG_MIN;

        int remaining = ((1 << n) - 1) ^ mask;

        for (int sub = remaining; sub; sub = (sub - 1) & remaining) {

            ans = max(
                ans,
                groupScore[sub] + solve(mask | sub, n)
            );
        }

        return dp[mask] = ans;
    }

    long long maxScore(vector<vector<long long>>& a) {
        int n = a.size();

        memset(dp, -1, sizeof(dp));

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    for (int j = i + 1; j < n; j++) {
                        if (mask & (1 << j)) {
                            groupScore[mask] += a[i][j];
                        }
                    }
                }
            }
        }

        return solve(0, n);
    }
};