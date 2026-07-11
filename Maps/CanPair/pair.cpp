#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
        int n = arr.size();
        if (n%2!=0) return false;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int rem = arr[i]%k;
            mp[rem]++;
        }
        for(auto p: mp){
            int ele = p.first;
            int target = k-ele;
            if(ele == target || ele == 0){
                if (mp[ele]%2!=0)
                    return false;
            }
            else{
                if(mp[target]){
                    if (mp[ele]!=mp[target]) return false;
                }
                else return false;
            }
        }
        return true;
    }
};