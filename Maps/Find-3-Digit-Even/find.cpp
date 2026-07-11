#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=100;i<1000;i+=2){
            int x = i;
            int a = x%10;
            x /= 10;
            int b = x%10;
            x /= 10;
            int c = x%10;
            x /= 10;
            if(mp.find(a)!=mp.end()){
                mp[a]--;
                if(mp[a]==0)mp.erase(a);
                if(mp.find(b)!=mp.end()){
                    mp[b]--;
                    if(mp[b]==0)mp.erase(b);
                    if(mp.find(c)!=mp.end()){
                        mp[c]--;
                        ans.push_back(i);
                        if(mp[c]==0)mp.erase(c);
                        mp[c]++;
                    }
                    mp[b]++;
                }
                mp[a]++;
            }
        }
        return ans;
    }
};