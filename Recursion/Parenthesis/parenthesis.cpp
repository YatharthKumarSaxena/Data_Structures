#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void helper(int n,vector<string> &v,int o = 0,int c = 0,string s = ""){
        if(o==n && c==n){
            v.push_back(s);
            return;
        }
        if(o>c && c<n)helper(n,v,o,c+1,s+")");
        if(o<n)helper(n,v,o+1,c,s+"(");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        helper(n,s);
        return s;
    }
};