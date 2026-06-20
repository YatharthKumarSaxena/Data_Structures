#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        int maxEle = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxEle){
                maxEle = nums[i];
                ans = 1;
                count = 1;
            }
            else if(nums[i]==maxEle){
                count++;
            }
            else{
                count = 0;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};