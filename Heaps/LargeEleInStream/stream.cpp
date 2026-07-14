#include <queue>
using namespace std;

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        if(pq.size()<k)return -1;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        vector<int>nums;
        KthLargest kLarge(k,nums);
        vector<int>ans;
        int n = arr.size();
        for(int i=0;i<n;i++){
            ans.push_back(kLarge.add(arr[i]));
        }
        return ans;
    }
};