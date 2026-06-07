#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> ans;
        while(i<n){
            if(nums[i]==i+1)i++;
            if(i>=n)break;
            int correctedIdx = nums[i]-1;
            if(nums[i]==nums[correctedIdx])i++;
            else swap(nums[i],nums[correctedIdx]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)ans.push_back(i+1);
        }
        return ans;
    }
};