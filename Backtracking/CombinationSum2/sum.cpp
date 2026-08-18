#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void doBacktrack(vector<vector<int>>& ans, vector<int>& arr,
                     vector<int>& helper, int target, int idx) {

        if(target == 0) {
            ans.push_back(helper);
            return;
        }

        int n = arr.size();

        for(int i = idx; i < n; i++) {

            // Same level par duplicate skip
            if(i > idx && arr[i] == arr[i - 1])
                continue;

            if(arr[i] > target)
                break;

            helper.push_back(arr[i]);

            // i + 1 → current element dobara use nahi hoga
            doBacktrack(ans, arr, helper, target - arr[i], i + 1);

            helper.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> helper;

        sort(arr.begin(), arr.end());

        doBacktrack(ans, arr, helper, target, 0);

        return ans;
    }
};