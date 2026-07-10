#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans(2);
        for(int i=0;i<nums.size();i++){
            int check = target-nums[i];
            if(mp.find(check)!=mp.end()){
                ans[0]=i;
                ans[1]=mp[check];
                return ans;
            }
            else mp[nums[i]]=i;
        }
        return ans;
    }
};