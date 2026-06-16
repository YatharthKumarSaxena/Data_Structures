#include <vector>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int maxSum = 0;
        int n = arr.size();
        for(int i=0;i<k;i++){
            maxSum += arr[i];
        }
        int prevSum = maxSum;
        for(int i=k;i<n;i++){
            int currSum = (prevSum-arr[i-k]+arr[i]);
            if(currSum>maxSum){
                maxSum = currSum;
            }
            prevSum = currSum;
        }
        return maxSum;
    }
};