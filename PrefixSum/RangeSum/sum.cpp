#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> querySum(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        int q = queries.size();
        vector<int>ans;
        for(int i=0;i<q;i++){
            int left = queries[i][0]-1;
            int right = queries[i][1]-1;
            if(left==0)ans.push_back(arr[right]);
            else ans.push_back(arr[right]-arr[left-1]);
        }
        return ans;
    }
};