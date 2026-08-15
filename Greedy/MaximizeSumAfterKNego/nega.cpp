#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximizeSum(vector<int>& nums, int k) {
        // code here
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cp = 0;
        int cn = 0;
        int cz = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<0)cn++;
            else if(nums[i]>0)cp++;
            else cz++;
        }
        int maxSum = 0;
        if(cn==0 && cz==0){
            for(int i=0;i<n;i++){
                maxSum += nums[i];
            }
            if(k%2 == 0){
                return maxSum;
            }else{
                return maxSum-2*nums[0];
            }
        }
        else if(cz>0 && cp>0 && cn==0){
            for(int i=0;i<n;i++){
                maxSum += nums[i];
            }
            return maxSum;
        }
        else if(cn>0){
            if(k==cn){
                for(int i=0;i<n;i++){
                    maxSum += abs(nums[i]);
                }
                return maxSum;
            }
            else if(k>cn){
                k -= cn;
                if(cz>0){
                    for(int i=0;i<n;i++){
                        maxSum += abs(nums[i]);
                    }
                    return maxSum;
                }else{
                    int minEle = INT_MAX;
                    for(int i=0;i<n;i++){
                        maxSum += abs(nums[i]);
                        minEle = min(abs(nums[i]),minEle);
                    }
                    if(k%2!=0)return maxSum-2*minEle;
                    return maxSum;
                }
            }else{
                for(int i = 0; i < k; i++) {
                    nums[i] = -nums[i];
                }
        
                for(int i = 0; i < n; i++) {
                    maxSum += nums[i];
                }
        
                return maxSum;
            }
        }
        return maxSum;
    }
};