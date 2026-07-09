#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return {-1};
        vector<int>nge(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(st.size()!=0 && nums[i]>=st.top())st.pop();
            if(st.size())nge[i]=st.top();
            st.push(nums[i]);
        }
        return nge;
    }
};