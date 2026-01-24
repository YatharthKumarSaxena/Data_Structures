#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void doRecusrion(vector<string>& ans,string helper,string s){
        if(s.size()==0){
    if (!helper.empty())
        ans.push_back(helper);
            return;
        }
        doRecusrion(ans,helper+s[0],s.substr(1));
        doRecusrion(ans,helper,s.substr(1));
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        doRecusrion(ans,"",s);
        sort(ans.begin(),ans.end());
        return ans;
    }
};