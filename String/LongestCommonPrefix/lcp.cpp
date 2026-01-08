#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minCount = INT_MAX;
        string ans = strs[0];
        for(int i=0;i<n;i++){
            int val = strs[i].size();
            if(val<minCount){
                minCount = val;
                ans = strs[i];
            }
        }
        int limit = 0;
        for(int i=0;i<minCount;i++){
            char c = ans[i];
            bool check = true;
            for(int j=0;j<n;j++){
                if(strs[j][i]!=c){
                    check = false;
                    break;
                }
            }
            if(!check)break;
            limit++;
        }
        return ans.substr(0,limit);
    }
};