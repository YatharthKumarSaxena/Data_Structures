#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        vector<int>ans(n-k+1,0);
        int i = 0;
        int j = k;
        unordered_map<int,int>mp;
        for(int t=0;t<k;t++){
            mp[arr[t]]++;
        }
        ans[0] = mp.size();
        for(int t=1;t<n-k+1;t++){
            mp[arr[i]]--;
            if(mp[arr[i]]==0) mp.erase(arr[i]);
            mp[arr[j]]++;
            ans[t]=mp.size();
            i++;
            j++;
        }
        return ans;
    }
};