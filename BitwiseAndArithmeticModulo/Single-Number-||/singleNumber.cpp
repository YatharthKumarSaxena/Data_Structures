#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(32,0);
        for(int k=0;k<32;k++){
            for(int i=0;i<n;i++){
                if(nums[i]>>k & 1)ans[k]++;
            }
        }
        for(int k=0;k<32;k++){
            ans[k] = ans[k]%3;
        }
        int finalVal = 0;
        long base = 1;
        for(int k=0;k<32;k++){
            finalVal += base*ans[k];
            base *= 2;
        }
        return finalVal;
    }
};