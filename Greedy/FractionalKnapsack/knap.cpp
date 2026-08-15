#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    typedef pair<double,int>pip;
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        priority_queue<pip>pq;
        int n = val.size();
        for(int i=0;i<n;i++){
            double qty = (double)val[i]/wt[i];
            pip p = {qty,i};
            pq.push(p);
        }
        double maxQty = 0;
        while(pq.size() && capacity>0){
            pip p = pq.top();
            pq.pop();
            int idx = p.second;
            int weight = wt[idx];
            int qty = val[idx];
            if(capacity>=weight){
                capacity -= weight;
                maxQty += qty;
            }else{
                maxQty += ((double)capacity / weight) * qty;
                capacity = 0;
            }
        }
        return maxQty;
    }
};
