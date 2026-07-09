#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n,1);
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size() && arr[i]>=arr[st.top()])st.pop();
            if(st.size())ans[i]=i-st.top();
            else ans[i] = i+1;
            st.push(i);
        }
        return ans;
    }
};