#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        int ans = 0;
        int n = answers.size();
        for(int i=0;i<n;i++){
            int key = answers[i]+1;
            if(key!=1){
                if(mp.find(key)==mp.end()){
                    ans += key;
                    mp[key]++;
                }
                else{
                    if(mp[key]==key-1){
                        mp.erase(key);
                    }else{
                        mp[key]++;
                    }
                }
            }else ans++;
        }
        return ans;
    }
};