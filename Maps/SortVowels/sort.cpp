#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        int n = s.length();
        string ans(n, '#');
        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                mp1[s[i]]++;
                if(mp2.find(s[i])==mp2.end()){
                    mp2[s[i]] = i;
                }
            }
        }
        map<int,vector<char>,greater<int>>mp3;
        for(auto Pair: mp1){
            int ele = Pair.second;
            char val = Pair.first;
            if(mp3.find(ele)==mp3.end()){
                mp3[ele] = {val};
            }else{
                mp3[ele].push_back(val);
            }
        }
        int idx = 0;
        bool foundCons = false;
        for(int i=0;i<n;i++){
            if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
                ans[i] = s[i];
            }else{
                if(!foundCons){
                    idx = i;
                    foundCons = true;
                }
            }
        }
        for(auto& Pair: mp3){
            sort(Pair.second.begin(),Pair.second.end(),
                [&](char a, char b){
                    return mp2[a] < mp2[b];
                }
            );
        }
        for(auto Pair: mp3){
            int count = Pair.first;
            vector<char> elements = Pair.second;
            int tot = elements.size();
            for(int j=0;j<tot;j++){
                char ele = elements[j];
                for(int k=0;k<count;k++){
                    if(ans[idx]=='#'){
                        ans[idx++] = ele; 
                    }else{
                        while(ans[idx]!='#')idx++;
                        ans[idx++] = ele;
                    }
                }
            }
        }
        return ans;
    }
};