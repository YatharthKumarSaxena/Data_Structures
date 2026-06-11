#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        if(satisfaction[n-1]<=0)return 0;
        vector<int>sufSum(n,0);
        sufSum[n-1] = satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            sufSum[i] += (satisfaction[i]+sufSum[i+1]);
        }
        int totalCost = 0;
        int prod = 1;
        for(int i=0;i<n;i++){
            if(sufSum[i]>=0){
                totalCost += prod*satisfaction[i];
                prod += 1;
            }

        }
        return totalCost;
    }
};