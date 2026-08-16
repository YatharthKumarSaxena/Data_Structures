#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(ans.size());
                ans += s[i];
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                    ans += s[i];
                }
            }else ans += s[i];
        }
        while(!st.empty()){
            ans.erase(st.top(),1);
            st.pop();
        }
        return ans;
    }
};