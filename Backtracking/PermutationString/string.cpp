#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    void doBackTrack(string s, string helper,vector<string>& ans){
        int n = s.size();
        if(n==0){
            ans.push_back(helper);
            return;
        }
        for(int i=0;i<n;i++){
            string rem = s.substr(0,i)+s.substr(i+1);
            helper += s[i];
            doBackTrack(rem,helper,ans);
            helper.pop_back();
        }
    }
    vector<string> permutation(string s) {
        // code here
        vector<string>ans;
        doBackTrack(s,"",ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};