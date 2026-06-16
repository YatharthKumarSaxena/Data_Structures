#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int k = minutes;
        int maxSum = 0;
        for(int i=0;i<k;i++){
            maxSum += customers[i]*grumpy[i];
        }
        int prevSum = maxSum;
        int idx = 0;
        for(int j=k;j<n;j++){
            int currSum = prevSum + (customers[j]*grumpy[j])- (customers[j-k]*grumpy[j-k]);
            if(currSum > maxSum){
                maxSum = currSum;
                idx = j-k+1;
            }
            prevSum = currSum;
        }
        for(int i=idx;i<idx+k;i++){
            grumpy[i] = 0;
        }
        int maxCusSatisfied = 0;
        for(int i=0;i<n;i++){
            if(!grumpy[i]) maxCusSatisfied += customers[i];
        }
        return maxCusSatisfied;
    }
};