#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mazorityEle = nums[0];
        int appearCount = 1;
        for(int i=1;i<n;i++){
            if(nums[i]!=mazorityEle){
                appearCount--;
                if(appearCount == 0){
                    mazorityEle = nums[i];
                    appearCount++;
                }
            }
            else appearCount++;
        }
        return mazorityEle;
    }
};