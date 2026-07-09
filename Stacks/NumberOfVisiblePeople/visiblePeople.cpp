#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        ans[n-1]=0;
        stack<int>st;
        st.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            int count = 0;
            while(st.size() && nums[i]>st.top()){
                st.pop();
                count++;
            }
            if(st.size() && nums[i]<st.top())count++;
            ans[i]=count;
            st.push(nums[i]);
        }
        return ans;
    }
};