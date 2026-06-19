#include <vector>
using namespace std;

class Solution1 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ansForK = 0;
        int i=0;
        int j=0;
        int oddCount = 0;
        while(j<n){
            if(nums[j]%2 != 0)oddCount++;
            while(oddCount>k){
                if(nums[i]%2 != 0)oddCount--;
                i++;
            }
            ansForK += (j-i+1);
            j++;
        }
        int ansForK_1 = 0;
        oddCount = 0;
        i = 0;
        j = 0;
        while(j<n){
            if(nums[j]%2 != 0)oddCount++;
            while(oddCount>k-1){
                if(nums[i]%2 != 0)oddCount--;
                i++;
            }
            ansForK_1 += (j-i+1);
            j++;
        }
        int ans = ansForK - ansForK_1;
        return ans;
    }
};


class Solution2 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        int oddCount = 0;
        while(j<n){
            if(nums[j]%2 != 0)oddCount++;
            while(oddCount>k){
                if(nums[i]%2 != 0)oddCount--;
                i++;
            }
            int copyOfI = i;
            int copyOfOddCount = oddCount;
            while(copyOfOddCount==k){
                ans++;
                if(nums[copyOfI]%2 != 0)copyOfOddCount--;
                copyOfI++;
            };
            j++;
        }
        return ans;
    }
};