#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int i=0;
        int j=0;
        int n=nums.size();
        int product=1;
        int ans = 0;
        while(j<n){
            product *= nums[j];
            while(product>=k){
                ans += (j-i);
                product /= nums[i];
                i++;
            }
            j++;
        }
        while(i<n){
            ans += (j-i);
            product /= nums[i];
            i++;          
        }
        return ans;
    }
};