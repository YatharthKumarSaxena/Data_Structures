#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    void fillSieve(vector<bool>& sieve){
        int n = sieve.size();
        for(int i=2;i<=sqrt(n);i++){
            if(sieve[i]){
                for(int j=i*i;j<n;j+=i){
                    sieve[j] = false;
                }
            }
        }
        return;
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        n = n-1;
        vector<bool>sieve(n+1,true);
        sieve[0] = false;
        sieve[1] = false;
        fillSieve(sieve);
        int totalPrimes = 0;
        for(int i=0;i<=n;i++){
            if(sieve[i])totalPrimes++;
        }
        return totalPrimes;
    }
};