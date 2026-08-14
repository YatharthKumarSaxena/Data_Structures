#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int cn=0,cz=0,cp=0;
        int n = arr.size();
        int minEle = INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]>0)cp++;
            else if(arr[i]<0)cn++;
            else cz++;
            minEle = min(minEle,arr[i]);
        }
        if(cz > 0 && cn == 0)return 0;
        else if(cz==0 && cp>0 && cn==0){
            return minEle;
        }
        int prod = 1;
        int maxEle = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]!=0) prod *= arr[i];
            if(arr[i]<0){
                maxEle = max(maxEle,arr[i]);
            }
        }
        if(cn>0 && cn%2 == 0){
            return prod/maxEle;
        }
        return prod;
    }
};