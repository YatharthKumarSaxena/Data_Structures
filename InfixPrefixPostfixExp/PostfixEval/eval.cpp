#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkOperator(string op){
       if(op == "+" || op == "-" || op == "*" || op == "/" || op == "^")return true;
       return false;
    }
    int solve(int val1, string op, int val2){
        if(op == "+")return val1+val2;
        else if(op == "-")return val1-val2;
        else if(op == "*")return val1*val2;
        else if(op == "/"){
            int res = val1/val2;
            if(val1*val2 < 0 && val1%val2)return res-1;
            return res;
        }
        return pow(val1,val2);
    }
    int evaluatePostfix(vector<string>& arr) {
        // code here
        int n = arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!checkOperator(arr[i])){
                st.push(stoi(arr[i]));
            }else{
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                int res = solve(val1,arr[i],val2);
                st.push(res);
            }
        }
        return st.top();
    }
};