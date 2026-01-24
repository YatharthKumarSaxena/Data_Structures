#include <vector>
using namespace std;

class Solution {
public:
    void doRecursion(vector<vector<int>> &ans, vector<int>helper, vector<int>arr){
        if(arr.size()==0){
            ans.push_back(helper);
            return;
        }
        int val = arr[0];
        arr.erase(arr.begin());
        doRecursion(ans, helper, arr);
        helper.push_back(val);
        doRecursion(ans, helper, arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>helper;
        doRecursion(ans,helper,nums);
        return ans;
    }
};