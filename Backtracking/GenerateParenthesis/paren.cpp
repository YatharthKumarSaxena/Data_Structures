#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void doRecursion(vector<string>& ans, string helper, int open, int closed, int n){
        if(open>n)return;
        if(closed+open==2*n){
            ans.push_back(helper);
            return;
        }
        if(open>closed)doRecursion(ans,helper+')',open,closed+1,n);
        doRecursion(ans,helper+'(',open+1,closed,n);
    }
    vector<string> generateParentheses(int n) {
        // code here
        vector<string> ans;
        doRecursion(ans,"",0,0,n/2);
        return ans;
    }
};