#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int doDP(string word1, string word2, int i, int j,vector<vector<int>>& dp){
        if(i==word1.size())return word2.size()-j;
        else if(j==word2.size())return word1.size()-i;
        else if(dp[i][j]!=-1)return dp[i][j];
        else if(word1[i]==word2[j])return dp[i][j] = doDP(word1,word2,i+1,j+1,dp);
        int ans = INT_MAX;
        ans = min(ans,doDP(word1,word2,i+1,j+1,dp)); // Replace
        ans = min(ans,doDP(word1,word2,i,j+1,dp)); // Insert
        ans = min(ans,doDP(word1,word2,i+1,j,dp)); // Delete
        ans += 1;
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1, -1));
        return doDP(word1,word2,0,0,dp);
    }
};