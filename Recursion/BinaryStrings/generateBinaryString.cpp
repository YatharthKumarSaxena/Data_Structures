#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    void doRecursion(int n, string helper, vector<string> &ans){
        if(helper.length()==n){
            ans.push_back(helper);
            return;
        }
        doRecursion(n,helper+'0',ans);
        doRecursion(n,helper+'1',ans);
    }
    vector<string> binstr(int n) {
        // code here
        vector<string>ans;
        doRecursion(n,"",ans);
        return ans;
    }
};