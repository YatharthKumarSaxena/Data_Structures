#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 != n2)return -1;
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<n1;i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        for(auto Pair: mp1){
            char ele = Pair.first;
            if(mp2.find(ele)==mp2.end())return -1;
            else if(mp1[ele]!=mp2[ele])return -1;
        }
        
        int i = n1 - 1;
        int j = n2 - 1;
        int ans = 0;
        
        while(i >= 0 && j >= 0) {
        
            if(s1[i] == s2[j]) {
                i--;
                j--;
            }
            else {
                i--;
                ans++;
            }
        }
        
        return ans;
    }
};
