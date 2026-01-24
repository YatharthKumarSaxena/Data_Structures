#include <vector>
#include <algorithm>
using namespace std;

// Only Works if Array has no Duplicate Elements
// User function Template for C++
class Solution {
  public:
    void generateSubArray(vector<vector<int>>&ans,vector<int>ansArray,vector<int> helper,int idx){
        if(idx == helper.size()){
            if(ansArray.size()==0)return;
            ans.push_back(ansArray);
            return;
        }
        generateSubArray(ans,ansArray,helper,idx+1);
        if(!ansArray.size() || ansArray[ansArray.size()-1] == helper[idx-1]){
            ansArray.push_back(helper[idx]);
            generateSubArray(ans,ansArray,helper,idx+1);
        }
    }
    vector<vector<int> > getSubArrays(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int>ansArray;
        generateSubArray(ans,ansArray,arr,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};