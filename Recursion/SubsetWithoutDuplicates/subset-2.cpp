#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void doRecursion(vector<vector<int>> &ans, vector<int>helper, vector<int>arr, int index){
        ans.push_back(helper);
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1]){
                continue;
            }
            helper.push_back(arr[i]);
            doRecursion(ans,helper,arr,i+1);
            helper.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>helper;
        sort(nums.begin(),nums.end());
        doRecursion(ans,helper,nums,0);
        return ans;
    }
};