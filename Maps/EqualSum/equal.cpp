#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = arr[i] + arr[j];
                if(mp.find(sum)!=mp.end()) return true;
                else mp[sum]++;
            }
        }
        return false;
    }
};