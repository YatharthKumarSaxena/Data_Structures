#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the Pivot Index
        int idx = -1;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                idx = i;
            }
        }
        // If No Pivot Index is found simply reverse the entire vector
        if(idx == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            sort(nums.begin()+idx+1,nums.end());
            // Find just greater number than nums[idx]
            int swapIdx = idx+1;
            while(swapIdx<n){
                if(nums[idx]>=nums[swapIdx])swapIdx++;
                else break;
            }
            swap(nums[idx],nums[swapIdx]);
        }
    }
};