#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            res ^= nums[i];
        }
        int k = 0;
        while(true){
            if(res>>k & 1){
                break;
            }
            k++;
        }
        int firstVal = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>>k & 1)firstVal ^= nums[i];
        }
        int secondVal = firstVal ^ res;
        vector<int>ans(2);
        ans[0] = firstVal;
        ans[1] = secondVal;
        return ans;
    }
};