#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp1;
        int n = s.size();
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
        }
        map<int,vector<char>,greater<int>>mp2;
        string ans = "";
        for(auto Pair: mp1){
            char ele = Pair.first;
            int count = Pair.second;
            mp2[count].push_back(ele);
        }
        for(auto Pair: mp2){
            vector<char> ele = Pair.second;
            int count = Pair.first;
            int tot = ele.size();
            for(int i=0;i<tot;i++){
                for(int j=0;j<count;j++){
                    ans += ele[i];
                }
            }
        }
        return ans;
    }
};