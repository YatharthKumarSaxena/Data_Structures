#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int>dir={1,-1,1,-1,2,-2,2,-2};
    vector<int>dic={2,2,-2,-2,1,1,-1,-1};
    bool checkIsInSafeState(vector<vector<int>>& ans, int i, int j, int n){
        if(i>=0 && i<=n-1 && j>=0 && j<=n-1 && ans[i][j]==-1)return true;
        return false;
    }
    bool doBacktrack(int count,vector<vector<int>>& ans, int i, int j,int n){
        if(count == n*n-1){
            return true;
        }
        for(int k=0;k<8;k++){
            int r = i+dir[k];
            int c = j+dic[k];
            if(checkIsInSafeState(ans,r,c,n)){
                ans[r][c] = count + 1;
                if(doBacktrack(count+1,ans,r,c,n))return true;
                ans[r][c] = -1;
            }
        }
        return false;
    }
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>>ans(n,vector<int>(n,-1));
        ans[0][0] = 0;
        if(doBacktrack(0,ans,0,0,n))return ans;
        return {};
    }
};