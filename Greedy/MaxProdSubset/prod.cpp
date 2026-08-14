#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MOD = 1000000007;
    long long modPow(long long a, long long b) {
        long long res = 1;
    
        while (b) {
            if (b & 1)
                res = res * a % MOD;
    
            a = a * a % MOD;
            b >>= 1;
        }
    
        return res;
    }
    
    long long modInverse(long long a) {
        a = (a % MOD + MOD) % MOD;
        return modPow(a, MOD - 2);
    }
    
    int findMaxProduct(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==1)return arr[0];
        int cn=0,cz=0,cp=0;
        int maxEle = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>0)cp++;
            else if(arr[i]<0)cn++;
            else cz++;
            maxEle = max(maxEle,arr[i]);
        }
        if(cp == 0 && cn == 0)return 0;
        if(cz > 0 && cn == 1 && cp == 0)return 0;
        if(cz==0){
            if(cn==0){
                long long prod = 1;
                for(int i=0;i<n;i++){
                    prod = (prod * arr[i]) % MOD;
                } 
                return prod;
            }
            
        }
        if(cn%2 == 0){
            long long prod = 1;
            for(int i=0;i<n;i++){
                if(arr[i]!=0) prod = (prod * arr[i]) % MOD;
            } 
            return prod;
        }
        if(cn%2 != 0){
            long long prod = 1;
            int maxEle = INT_MIN;
            for(int i=0;i<n;i++){
                if(arr[i]!=0) prod = (prod * arr[i]) % MOD;
                if(arr[i]<0)maxEle = max(arr[i],maxEle);
            } 
            return (prod * modInverse(maxEle) % MOD + MOD) % MOD;
        }
        return 0;
    }
};
