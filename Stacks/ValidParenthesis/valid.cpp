#include <stack>
#include <string>
using namespace std;
class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        int n = s.size();
        if(n%2!=0)return false;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(st.size() && (
                (st.top()=='(' && s[i]==')') || 
                (st.top()=='{' && s[i]=='}') || 
                (st.top()=='[' && s[i]==']'))
            ){
                st.pop();
            }
            else return false;
        }
        return st.empty();
    }
};