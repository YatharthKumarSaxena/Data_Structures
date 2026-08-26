#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void doRecursion(vector<vector<int>>& ans, vector<int>helper, int n, int k){
        if(helper.size()==k){
            ans.push_back(helper);
            return;
        }
        int size = helper.size();
        for(int i=1;i<=n;i++){
            if(size > 0 && helper[size-1]<i){
                helper.push_back(i);
                doRecursion(ans,helper,n,k);
                helper.pop_back();
            }
            if(size==0){
                helper.push_back(i);
                doRecursion(ans,helper,n,k);
                helper.pop_back();
            }

        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        doRecursion(ans,{},n,k);
        return ans;
    }
};