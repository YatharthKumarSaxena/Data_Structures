#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkOperator(char op){
       if(op == '+' || op == '%' || op == '-' || op == '*' || op == '/' || op == '^')return true;
       return false;
    }
    string solve(string val1, char op, string val2){
        string ans = "";
        ans += op;
        ans += val1;
        ans += val2;
        return ans;
    }
    string postToPre(string s) {
        // code here
        int n = s.size();
        stack<string>st;
        for(int i=0;i<n;i++){
            if(!checkOperator(s[i])){
                st.push(string(1,s[i]));
            }else{
                string val2 = st.top();
                st.pop();
                string val1 = st.top();
                st.pop();
                string res = solve(val1,s[i],val2);
                st.push(res);
            }
        }
        return st.top();
    }
};