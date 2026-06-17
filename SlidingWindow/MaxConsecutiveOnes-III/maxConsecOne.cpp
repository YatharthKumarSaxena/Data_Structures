#include <vector>
#include <climits>
using namespace std;

class Solution1 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int currLen = INT_MIN;
        int maxLen = INT_MIN;
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j])j++;
            else{
                if(flips<k){
                    flips++;
                    j++;
                }else{
                    currLen = j-i;
                    maxLen = max(maxLen,currLen);
                    while(nums[i])i++;
                    i++;
                    j++;
                }
            }
        }
        currLen = j-i;
        maxLen = max(maxLen,currLen);
        return maxLen;
    }
};


class Solution2 {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int zeroPos = -1;
        int maxLen = INT_MIN;
        int i=0;
        int j=0;
        while(j<n){
            int prev = zeroPos;
            if(!nums[j]){
                count++;
                zeroPos = j;
            }
            if(count<=1)j++;
            else{
                maxLen = max(maxLen,j-i);
                i = prev+1;
                count--;
                j++;
            }
        }
        maxLen = max(maxLen,j-i);
        return maxLen-1;
    }
};