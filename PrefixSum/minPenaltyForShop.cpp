#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>preSum(n+1,0);
        vector<int>sufSum(n+1,0);
        vector<int>overallPenalty(n+1,0);
        for(int i=1;i<=n;i++){
            preSum[i] += preSum[i-1];
            if(customers[i-1]=='N')preSum[i] += 1;
        }
        for(int i=n-1;i>=0;i--){
            sufSum[i] += sufSum[i+1];
            if(customers[i]=='Y')sufSum[i] += 1;
        }
        for(int i=0;i<=n;i++){
            overallPenalty[i] = preSum[i]+sufSum[i];
        }
        int minIdx = 0;
        int idx = 0;
        int minPenalty = overallPenalty[0];
        while(idx<=n){
            if(minPenalty > overallPenalty[idx]){
                minIdx = idx;
                minPenalty = overallPenalty[idx];
            }
            idx += 1;
        }
        return minIdx;
    }
};