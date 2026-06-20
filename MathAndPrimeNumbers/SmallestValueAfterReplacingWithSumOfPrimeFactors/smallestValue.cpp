#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int n){
        if (n<=1) return false;

        for(int i=2;i<=int(sqrt(n));i++){
            if(n%i == 0) return false;
        }

        return true;
    }

    int smallestValue(int n) {
        if(isPrime(n))return n;
        int sum = 0;
        int m = n;
        for(int i=2;i<=sqrt(n);i++){
            while(m%i == 0 && isPrime(i)){
                sum += i;
                m /= i;
            }
        }
        for(int i=sqrt(n);i>0;i--){
            while(m%(n/i) == 0 && isPrime(n/i)){
                sum += (n/i);
                m /= (n/i);
            }
        }
        if(sum == n)return sum;
        return smallestValue(sum);
    }
};