#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int n = nums.size();
        int mn = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]%2)nums[i]*=2;
            pq.push(nums[i]);
            mn = min(nums[i],mn);
        }
        int mx = pq.top();
        int ans = INT_MAX;
        while(mx%2==0){
            mx /= 2;
            pq.pop();
            pq.push(mx);
            mn = min(mx,mn);
            mx = pq.top();
            ans = min(mx-mn,ans);
        }
        return ans;
    }
};