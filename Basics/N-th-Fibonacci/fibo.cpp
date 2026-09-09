class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n<=1)return n;
        int a = 0;
        int b = 1;
        for(int i=0;i<=n-2;i++){
            int temp = a;
            a = b;
            b = temp+b;
        }
        return b;
    }
};