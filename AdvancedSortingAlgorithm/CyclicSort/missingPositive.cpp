#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0)continue;
            else{
                if(nums[i]==ans)ans += 1;
                else if(nums[i]<ans)continue;
                else return ans;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<=0 || nums[i]>n)i++;
            else{
                int correctedIdx = nums[i]-1;
                if(nums[i]==i+1 || nums[correctedIdx]==nums[i])i++;
                else swap(nums[i],nums[correctedIdx]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};