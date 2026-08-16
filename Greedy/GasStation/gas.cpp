#include <vector>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int total = 0;
        int tank = 0;
        int start = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            total += (gas[i]-cost[i]);
            tank += (gas[i] - cost[i]);
            if(tank<0){
                tank = 0;
                start = i+1;
            }
        }
        if(total<0)return -1;
        return start;
    }
};