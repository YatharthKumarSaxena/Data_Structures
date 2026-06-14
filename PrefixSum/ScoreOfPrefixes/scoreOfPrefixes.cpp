#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>ans(n,0);
        ans[0] = nums[0];
        for(int i=1;i<n;i++){
            ans[i] = max((long long) nums[i],ans[i-1]);
        }
        for(int i=0;i<n;i++){
            ans[i] += nums[i];
        }
        for(int i=1;i<n;i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};