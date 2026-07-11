#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int reverseDigit(int n){
        int ans = 0;
        while(n){
            ans *= 10;
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] -= reverseDigit(nums[i]);
        }
        int count = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            count = count% 1000000007;
            if(mp.find(nums[i]) != mp.end()){
                count += mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return count%1000000007;
    }
};