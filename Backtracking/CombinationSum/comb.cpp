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

            if(arr[i] > target)
                break;

            helper.push_back(arr[i]);

            // i -> same element dobara use ho sakta hai
            doBacktrack(ans, arr, helper, target - arr[i], i);

            helper.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> helper;

        sort(arr.begin(), arr.end());

        doBacktrack(ans, arr, helper, target, 0);

        return ans;
    }
};