#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reversePartOfArray(int startIdx, int endIdx, vector<int> &nums){
        if(startIdx < 0 || endIdx >= nums.size())return;
        // nums.end()-nums.size() = nums.begin()
        reverse(nums.begin()+startIdx, nums.end()-nums.size()+endIdx+1);
        return;
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k=k%n;
        reversePartOfArray(0,n-k-1,nums);
        reversePartOfArray(n-k,n-1,nums);
        reversePartOfArray(0,n-1,nums);
        return;
    }
};