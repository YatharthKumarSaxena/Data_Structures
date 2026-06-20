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
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        int mx = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx)mx = nums[i];
        }
        vector<bool>sieve(mx+1,true);
        if(mx+1>0)sieve[0] = false;
        if(mx+1>1)sieve[1] = false;
        fillSieve(sieve);

        vector<int>possiblePrimes;
        for(int i=0;i<=mx+1;i++){
            if(sieve[i])possiblePrimes.push_back(i);
        }

        int totalPossiblePrimes = possiblePrimes.size();
        vector<bool>taken(totalPossiblePrimes,false);

        for(int i=0;i<totalPossiblePrimes;i++){
            for(int j=0;j<n;j++){
                if(nums[j]%possiblePrimes[i]==0){
                    taken[i] = true;
                    break;
                }
            }
        }

        int ans = 0;

        for(int i=0;i<totalPossiblePrimes;i++){
            if(taken[i])ans++;
        }

        return ans;
    }
};