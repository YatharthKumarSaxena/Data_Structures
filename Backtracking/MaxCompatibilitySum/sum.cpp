#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveByBackTrack(int i, int n, int& ans, int& currAns, vector<vector<int>>& score, vector<bool>& visited){
        if(i==n){
            ans = max(currAns,ans);
            return;
        }
        for(int k=0;k<n;k++){
            if(!visited[k]){
                currAns += score[i][k];
                visited[k] = true;
                solveByBackTrack(i+1,n,ans,currAns,score,visited);
                currAns -= score[i][k];
                visited[k] = false;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        int m = students[0].size();
        vector<vector<int>> score(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    score[i][j] += (students[i][k]==mentors[j][k]);
                }
            }
        }
        vector<bool> visited(n,false);
        int ans = 0;
        int currAns = 0;
        solveByBackTrack(0,n,ans,currAns,score,visited);
        return ans;
    }
};