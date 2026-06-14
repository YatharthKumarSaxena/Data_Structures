#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            nums[i]=nums[i-1]+nums[i];
        }
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int target = queries[i];
            int lo = 0;
            int hi = n-1;
            int mid = lo+(hi-lo)/2;
            while(lo<=hi){
                mid = lo+(hi-lo)/2;
                if(nums[mid]<=target){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
            ans[i]=hi+1;
        }
        return ans;
    }
};