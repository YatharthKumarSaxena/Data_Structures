#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int horPiece = 1;
        int verPiece = 1;

        int horIn = 0;
        int verIn = 0;

        long long ans = 0;

        int nx = x.size();
        int ny = y.size();

        while (horIn < nx && verIn < ny) {

            if (x[horIn] > y[verIn]) {
                // x = vertical cut
                ans += (long long)horPiece * x[horIn];
                horIn++;
                verPiece++;
            }
            else {
                // y = horizontal cut
                ans += (long long)verPiece * y[verIn];
                verIn++;
                horPiece++;
            }
        }

        while (horIn < nx) {
            ans += (long long)horPiece * x[horIn];
            horIn++;
            verPiece++;
        }

        while (verIn < ny) {
            ans += (long long)verPiece * y[verIn];
            verIn++;
            horPiece++;
        }

        return ans;
    }
};