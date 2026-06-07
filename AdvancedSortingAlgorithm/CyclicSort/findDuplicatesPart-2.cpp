#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int>ans;
        while(i<n){
            int correctedIdx = nums[i]-1;
            if(nums[i]==i+1 || nums[correctedIdx]==nums[i]){
                i+=1;
            }
            else{
                swap(nums[i],nums[correctedIdx]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};