#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(k<=1)return 0;
        long long n = nums.size();
        long long ans = 0;
        long long i=0;
        long long j=0;
        long long score = 0;
        long long winSum = 0;
        while(j<n){
            winSum += nums[j];
            score = winSum * (j-i+1);
            while(score>=k){
                winSum -= nums[i];
                i++;
                score = winSum * (j-i+1);
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};