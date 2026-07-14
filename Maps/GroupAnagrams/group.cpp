#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            string value = arr[i];
            sort(arr[i].begin(),arr[i].end());
            string key = arr[i];
            mp[key].push_back(value);
        }
        for(auto p: mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};