#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        vector<int>ans(n);
        int prodVar = 1;
        for(int i=0;i<n;i++){
            pre[i] = prodVar;
            prodVar *= nums[i];
        }
        prodVar = 1;
        for(int i=n-1;i>=0;i--){
            suf[i] = prodVar;
            prodVar *= nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i] = pre[i] * suf[i];
        }
        return ans;
    }
};