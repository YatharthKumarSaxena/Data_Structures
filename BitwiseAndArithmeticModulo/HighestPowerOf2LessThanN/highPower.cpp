// User function Template for C++
class Solution1 {
  public:
    long long int nthPosition(long long int n) {
        // code here
        int iterations = 6;
        int base = 1;
        for(int i=1;i<=iterations;i++){
            long long rightShiftVal = n>>base;
            base *= 2;
            n |= rightShiftVal;
        }
        return (n+1)/2;
    }
};

// User function Template for C++
class Solution2 {
  public:
    long long int nthPosition(long long int n) {
        // code here
        long long ans = n;
        while(n>0){
            ans = n;
            n &= n-1;
        }
        return ans;
    }
};