#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<char,int>pip;
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pip>pq;
        for(auto Pair: mp){
            pq.push(Pair);
        }
        string ans = "";
        while(pq.size()){
            pip p1 = pq.top();
            pq.pop();
            int freq = p1.second;
            char largestChar = p1.first;
            int len1 = min(repeatLimit,freq);
            for(int i=0;i<len1;i++){
                ans += largestChar;
            }
            if(freq-len1>0){
                freq -= len1;
                if (pq.empty()) break;
                pip p2 = pq.top();
                pq.pop();
                int len2 = p2.second;
                char secondLargeChar = p2.first;
                ans += secondLargeChar;
                p2.second--;
                p1.second = freq;
                if(p2.second>0)pq.push(p2);
                if(freq>0)pq.push(p1);
            }
        }
        return ans;
    }   
};