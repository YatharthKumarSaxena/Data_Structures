class Solution {
  public:
    int doSum(int &sum,int n){
        if(n==0)return 0;
        sum+=n;
        doSum(sum,n-1);
    }
    int findSum(int n) {
        // code here
        int sum = 0;
        doSum(sum,n);
        return sum;
    }
};
