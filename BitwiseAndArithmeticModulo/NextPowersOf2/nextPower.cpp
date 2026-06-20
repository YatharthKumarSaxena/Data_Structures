class Solution {
  public:
    int nextPowerOfTwo(int n) {
        // code here
        int ans = n;
        int count = 0;
        while(n){
            ans = n;
            n &= (n-1);
            count++;
        }
        if(count > 1)ans *= 2;
        return ans;
    }
};