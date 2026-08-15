#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int>pip;
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pip>pq;
        int n = boxTypes.size();
        for(int i=0;i<n;i++){
            pip p = {boxTypes[i][1],boxTypes[i][0]};
            pq.push(p);
        }
        int ans = 0;
        while(pq.size() && truckSize>0){
            pip p = pq.top();
            pq.pop();
            int boxes = p.second;
            int units = p.first;
            if(truckSize - boxes < 0){
                boxes = truckSize;
                truckSize = 0;
            }else truckSize -= boxes;
            ans += boxes*units;
        }
        return ans;
    }
};