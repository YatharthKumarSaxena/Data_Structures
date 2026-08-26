#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void doRecursion(vector<string>& ans, string digit, string helper, int idx){
        int n = digit.size();
        if(idx==n){
            ans.push_back(helper);
            return;
        }
        int offset = (digit[idx] - '2') * 3;
        if (digit[idx] > '7')
            offset++;
        int limit = (digit[idx] == '7' || digit[idx] == '9') ? 4 : 3;
        for(int i=0;i<limit;i++){
            char character = 'a' + offset + i;
            doRecursion(ans,digit,helper+character,idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        doRecursion(ans,digits,"",0);
        return ans;
    }
};