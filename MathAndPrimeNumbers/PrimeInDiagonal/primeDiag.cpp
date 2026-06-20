#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if(n<=1)return false;
        // code here
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0)return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int maxPrime = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(isPrime(nums[i][i])){
                maxPrime = max(maxPrime,nums[i][i]);
            }
            if(isPrime(nums[i][n-i-1])){
                maxPrime = max(maxPrime,nums[i][n-i-1]);
            }
        }
        return maxPrime;
    }
};