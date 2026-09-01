#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkOperator(string op){
       if(op == "+" || op == "%" || op == "-" || op == "*" || op == "/" || op == "^")return true;
       return false;
    }
    int solve(int val1, string op, int val2){
        if(op=="+")return val1+val2;
        else if(op=="-")return val1-val2;
        else if(op=="*")return val1*val2;
        else if(op=="/"){
            int res = val1/val2;
            if(val1*val2<0 && val1%val2)return res-1;
            return res;
        }
        return pow(val1,val2);
    }
    int evaluatePrefix(vector<string>& arr) {
        // code here
        stack<int>st;
        stack<string>op;
        int n = arr.size();
        for(int i=n-1;i>=0;i--){
            string term = arr[i];
            if(!checkOperator(term)){
                st.push(stoi(term));
            }else{
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                int res = solve(val1,term,val2);
                st.push(res);
            }
        }
        return st.top();
    }
};