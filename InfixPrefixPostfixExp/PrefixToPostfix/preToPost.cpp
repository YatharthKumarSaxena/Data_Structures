#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkOperator(string op){
       if(op == "+" || op == "%" || op == "-" || op == "*" || op == "/" || op == "^")return true;
       return false;
    }
    string solve(string val1, string op, string val2){
        string ans = "";
        ans += val1;
        ans += val2;
        ans += op;
        return ans;
    }
    string preToPost(string &s) {
        // code here
        stack<string>st;
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            string term = string(1,s[i]);
            if(!checkOperator(term)){
                st.push(term);
            }else{
                string val1 = st.top();
                st.pop();
                string val2 = st.top();
                st.pop();
                string res = solve(val1,term,val2);
                st.push(res);
            }
        }
        return st.top();
    }
};