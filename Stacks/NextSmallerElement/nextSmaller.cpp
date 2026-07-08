#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int>ans(n,-1);
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size() && arr[i]<=st.top())st.pop();
            if(st.size()) ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};