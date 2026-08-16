#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int ans = 0;
        int n = pairs.size();
        int currEnd = pairs[0][1];
        int removals = 0;
        for(int i=1;i<n;i++){
            int nextStart = pairs[i][0];
            int nextEnd = pairs[i][1];
            if(nextStart <= currEnd){
                removals++;
                currEnd = min(currEnd,nextEnd);
            }else{
                currEnd = nextEnd;
            }
        }
        return n-removals;
    }
};