#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        ans[n-1]=arr[n-1];
        stack<int>st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size() && st.top()>arr[i])st.pop();
            if(st.size())ans[i]=arr[i]-st.top();
            else ans[i]=arr[i];
            st.push(arr[i]);
        }
        return ans;
    }
};