#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int reverseInteger(int n){
        long long ans = 0;
        while(n>0){
            int rem = n%10;
            ans *= 10;
            ans += rem;
            n /= 10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(reverseInteger(nums[i]));
        }
        unordered_set<int>s;
        for(int i=0;i<2*n;i++){
            s.insert(nums[i]);
        }
        return s.size();
    }
};