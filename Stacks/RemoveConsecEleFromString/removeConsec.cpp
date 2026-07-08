#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        if(n==0)return "";
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.size() || st.top() != s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            char val = st.top();
            ans = string(1,val)+ans;
            st.pop();
        }
        return ans;
    }
};