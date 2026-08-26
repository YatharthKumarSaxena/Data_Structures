#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void doRecursion(vector<vector<int>>& ans,
                     vector<int>& arr,
                     vector<int>& helper,
                     int index) {
        
        int n = arr.size();

        ans.push_back(helper);

        for (int i = index; i < n; i++) {

            if (i > index && arr[i - 1] == arr[i])
                continue;

            helper.push_back(arr[i]);

            doRecursion(ans, arr, helper, i + 1);

            helper.pop_back();
        }
    }

    vector<vector<int>> findSubsets(vector<int>& arr) {
        
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        vector<int> helper;

        doRecursion(ans, arr, helper, 0);

        return ans;
    }
};