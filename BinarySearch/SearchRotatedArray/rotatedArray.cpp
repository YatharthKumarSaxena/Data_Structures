#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Find the Peak Index
        int peakIdx = -1;
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target)return mid; // Luck Hits
            if(mid && mid<hi && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                peakIdx = mid+1;
                break;
            }
            if(mid && mid<hi && nums[mid-1]>nums[mid] && nums[mid]<nums[mid+1]){
                peakIdx = mid;
                break;
            }
            else if(nums[mid]>nums[hi])lo = mid+1;
            else hi = mid-1;
        }
        int idx = -1;
        if(peakIdx == -1){ // Means Only Single Binary Search will do its work
            lo = 0;
            hi = nums.size()-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(nums[mid]==target){
                    idx = mid;
                    break;
                } 
                else if(nums[mid]<target)lo = mid+1;
                else hi = mid-1;
            }
        }
        else { // 2 Binary Search will give answer
            lo = 0;
            hi = peakIdx-1;
            if(target>=nums[lo] && target <= nums[hi]){
                while(lo<=hi){
                    int mid = lo+(hi-lo)/2;
                    if(nums[mid]==target){
                        idx = mid;
                        break;
                    }
                    else if(nums[mid]<target)lo = mid+1;
                    else hi = mid-1;
                }
            }
            else{
                lo = peakIdx;
                hi = nums.size()-1;
                while(lo<=hi){
                    int mid = lo+(hi-lo)/2;
                    if(nums[mid]==target){
                        idx = mid;
                        break;
                    }
                    else if(nums[mid]<target)lo = mid+1;
                    else hi = mid-1;
                }
            }
        }
        return idx;
    }
};