#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefMax(n,0);
        prefMax[0] = nums[0];
        vector<int>suffMin(n,0);
        suffMin[n-1] = nums[n-1];
        vector<int>score(n,0);
        for(int i=1;i<n;i++){
            prefMax[i] = max(nums[i],prefMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffMin[i] = min(nums[i],suffMin[i+1]);
        }
        for(int i=0;i<n;i++){
            score[i] = prefMax[i]-suffMin[i];
            if(score[i]<=k)return i;
        }
        return -1;
    }
};