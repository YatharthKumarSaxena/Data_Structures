#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0)return 0;
        int count = 0;
        unordered_map<int,int>mp;
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        for(int i=0;i<n;i++){
            int ele = nums[i];
            if(ele == k)count++;
            int searchEle = ele-k;
            if(mp.find(searchEle)!=mp.end())count += mp[searchEle];
            mp[nums[i]]++;
        }
        return count;
    }
};