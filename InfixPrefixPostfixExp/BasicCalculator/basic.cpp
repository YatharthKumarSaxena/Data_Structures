#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prio(char op){
        if(op == '/' || op == '*')return 2;
        return 1;
    }
    long long solve(long long val1, char op, long long val2){
        if(op=='+')return val1+val2;
        else if(op=='-')return val1-val2;
        else if(op=='*')return val1*val2;
        return val1/val2;
    }
    int calculate(string s) {
        string temp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '-'){
                int j = i - 1;
                // previous non-space character
                while(j >= 0 && s[j] == ' ')
                    j--;
                // unary minus
                if(j < 0 || s[j] == '(' || s[j] == '+' ||
                s[j] == '-' || s[j] == '*' || s[j] == '/'){
                    temp += '0';
                }
            }
            temp += s[i];
        }
        s = temp;
        int n = s.size();
        stack<long long>st;
        stack<char>op;
        for(int i=0;i<n;i++){
            if(s[i]==' ')continue;
            else if(s[i]=='(')op.push(s[i]);
            else if(s[i]>=48 && s[i]<=57){
                long long num = 0;
                while(i < n && s[i] >= 48 && s[i] <= 57){
                    num = num * 10 + (s[i] - 48);
                    i++;
                }
                st.push(num);
                i--;
            }
            else if(s[i]==')'){
                while(op.top()!='('){
                    long long val2 = st.top();
                    st.pop();
                    long long val1 = st.top();
                    st.pop();
                    char operation = op.top();
                    op.pop();
                    long long result = solve(val1,operation,val2);
                    st.push(result);
                }
                op.pop();
            }
            else if(op.size() && op.top()=='(')op.push(s[i]);
            else if(!op.size() || prio(s[i])>prio(op.top()))op.push(s[i]);
            else{
                while(op.size() && op.top() != '(' &&
      prio(s[i]) <= prio(op.top())){
                    long long val2 = st.top();
                    st.pop();
                    long long val1 = st.top();
                    st.pop();
                    char operation = op.top();
                    op.pop();
                    long long result = solve(val1,operation,val2);
                    st.push(result);
                }
                op.push(s[i]);
            }
        }
        while (!op.empty()) {
            long long val2 = st.top(); st.pop();
            long long val1 = st.top(); st.pop();

            char operation = op.top(); op.pop();

            st.push(solve(val1, operation, val2));
        }
        return st.top();
    }
};