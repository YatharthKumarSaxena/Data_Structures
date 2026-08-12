#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int moves = 1; moves <= n; moves++) {
            for (int eggs = 1; eggs <= k; eggs++) {
                dp[eggs][moves] =
                    dp[eggs - 1][moves - 1] +
                    dp[eggs][moves - 1] + 1;

                if (dp[eggs][moves] >= n)
                    return moves;
            }
        }

        return n;
    }
};