#include <iostream>
using namespace std;

// Worst
class Solution1 {
  public:
    int gcd(int a, int b) {
        // code here
        int digit = min(a,b);
        for(int i=digit;i>1;i--){
            if(a%i == 0 && b%i == 0)return i;
        }
        return 1;
    }
};

// Optimized
class Solution2 {
  public:
    int euclidDivision(int a, int b){
        if (a<b){
            if(b%a==0)return a;
            int rem = b%a;
            return euclidDivision(a,rem);
        }else {
            if(a%b==0)return b;
            int rem = a%b;
            return euclidDivision(b,rem);        
        }
        return 1;
    }
    int gcd(int a, int b) {
        return euclidDivision(a,b);
    }
};

// Clean and Best
class Solution {
  public:
    int gcd(int a, int b) {
       if (b==0)return a;
       return gcd(b,a%b);
    }
};
