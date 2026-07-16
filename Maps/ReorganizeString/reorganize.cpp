#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        if(n<=1)return s;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int maxFreq = mp[s[0]];
        for(auto p: mp){
            int freq = p.second;
            if(freq > (n+1)/2)return "";
            if(maxFreq < freq){
                maxFreq = freq;
            }
        }
        string ans(n,'0');
        int idx = 0;
        for(auto p: mp){
            if(maxFreq == p.second){
                char ele = p.first;
                while(mp[ele]){
                    ans[idx] = ele;
                    mp[ele]--;
                    idx += 2;
                }
                break;
            }
        }
        if(idx < n){
            for(auto p: mp){
                char ele = p.first;
                while(mp[ele]){
                    if(idx >= n)break;
                    ans[idx] = ele;
                    mp[ele]--;
                    idx += 2;
                }
            }
        }
        idx = 1;
        for(auto p: mp){
            char ele = p.first;
            while(mp[ele]>0 && idx<n){
                ans[idx] = ele;
                mp[ele]--;
                idx += 2;
            }
        }
        return ans;
    }
};