#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doRecursion(vector<int>& matchsticks,vector<int>& sides, int index, int target){
        if(index==matchsticks.size())return true;
        int stick = matchsticks[index];
        for(int i=0;i<4;i++){
            if(sides[i]+stick>target)continue;
            sides[i]+=stick;
            if(doRecursion(matchsticks,sides,index+1,target))return true;
            sides[i]-=stick;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int checkSum = 0;
        int n = matchsticks.size();
        if(n<4)return false;
        for(int i=0;i<n;i++){
            checkSum += matchsticks[i];
        }
        if(checkSum%4!=0)return false;
        int target = checkSum/4;
        for(int i=0;i<n;i++){
            if(matchsticks[i]>target)return false;
        }
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int>sides(4,0);
        return doRecursion(matchsticks,sides,0,target);
    }
};