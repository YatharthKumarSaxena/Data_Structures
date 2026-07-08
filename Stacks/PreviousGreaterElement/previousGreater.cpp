#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> st;
        vector<int>ans(n,-1);
        st.push(arr[0]);
        for(int i=1;i<n;i++){
            while(st.size() && arr[i]>=st.top())st.pop();
            if(st.size()) ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};