#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int totalOps = 0;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++) mp[nums[i]]++;
        for(auto p: mp){
            int ele = p.first;
            int target = k - ele;
            if(ele == target){
                while(mp[ele] > 1){
                    totalOps += 1;
                    mp[ele] -= 2;
                }
            }
            else
                if(mp.find(target)!=mp.end() && ele<target)
                    totalOps += min(mp[ele],mp[target]);
        }
        return totalOps;
    }
};