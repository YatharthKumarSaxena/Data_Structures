#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        if(n==0)return 0;
        int maxLen = 0;
        vector<int>pre0(n,0),pre1(n,0);
        if(arr[0]){
            pre1[0] = 1;
        }else{
            pre0[0] = 1;
        }
        for(int i=1;i<n;i++){
            pre0[i] += pre0[i-1];
            pre1[i] += pre1[i-1];
            if(arr[i]){
                pre1[i] += 1;
            }else{
                pre0[i] += 1;

            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int diff = pre0[i]-pre1[i];
            if(diff == 0)maxLen = max(maxLen,i+1);
            else{
                if(mp.find(diff)==mp.end()){
                    mp[diff] = i;
                }
                if(mp.find(diff)!=mp.end()){
                    maxLen = max(maxLen,i-mp[diff]);
                }
            }
        }
        return maxLen;
    }
};