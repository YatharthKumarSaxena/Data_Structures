#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] = nums[i-1]+nums[i];
        }
        int idx = -1;
        for(int i=0;i<n;i++){
            int leftVal = i==0? 0:nums[i-1];
            int rightVal = nums[n-1]-nums[i];
            if(leftVal == rightVal){
                idx = i;
                break;
            }
        }
        return idx;
    }
};