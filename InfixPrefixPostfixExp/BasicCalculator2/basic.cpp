#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prio(char op){
        if(op == '/' || op == '*')return 2;
        return 1;
    }
    int solve(int val1, char op, int val2){
        if(op=='+')return val1+val2;
        else if(op=='-')return val1-val2;
        else if(op=='*')return val1*val2;
        return val1/val2;
    }
    int calculate(string s) {
        int n = s.size();
        stack<int>st;
        stack<char>op;
        for(int i=0;i<n;i++){
            if(s[i]==' ')continue;
            else if(s[i]>=48 && s[i]<=57){
                int num = 0;
                while(i < n && s[i] >= 48 && s[i] <= 57){
                    num = num * 10 + (s[i] - 48);
                    i++;
                }
                st.push(num);
                i--;
            }
            else if(!op.size() || prio(s[i])>prio(op.top()))op.push(s[i]);
            else{
                while(op.size() && prio(s[i])<=prio(op.top())){
                    int val2 = st.top();
                    st.pop();
                    int val1 = st.top();
                    st.pop();
                    char operation = op.top();
                    op.pop();
                    int result = solve(val1,operation,val2);
                    st.push(result);
                }
                op.push(s[i]);
            }
        }
        while (!op.empty()) {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            char operation = op.top(); op.pop();

            st.push(solve(val1, operation, val2));
        }
        return st.top();
    }
};