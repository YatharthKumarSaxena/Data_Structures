#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*The function takes an array of heights, width and
    length as its 3 arguments where each index i value
    determines the height, width, length of the ith box.
    Here n is the total no of boxes.*/
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // Your code here
        int n = height.size();
        vector<vector<int>>cuboids;
        for(int i=0;i<n;i++){
            // Orientation 1
            cuboids.push_back({
                min(width[i], length[i]),
                max(width[i], length[i]),
                height[i]
            });

            // Orientation 2
            cuboids.push_back({
                min(height[i], length[i]),
                max(height[i], length[i]),
                width[i]
            });

            // Orientation 3
            cuboids.push_back({
                min(height[i], width[i]),
                max(height[i], width[i]),
                length[i]
            });
        }
        sort(cuboids.begin(),cuboids.end());
        int m = cuboids.size();
        vector<int> dp(m);
        int maxHeight = 0;
        for(int i=0;i<m;i++){
            dp[i] = cuboids[i][2];
            for(int j=0;j<i;j++){
                if (cuboids[j][0] < cuboids[i][0] &&
                    cuboids[j][1] < cuboids[i][1]) {
                    
                    dp[i] = max(dp[i],
                                dp[j] + cuboids[i][2]);
                    }
            }
            maxHeight = max(dp[i],maxHeight);
        }
        return maxHeight;
    }
};