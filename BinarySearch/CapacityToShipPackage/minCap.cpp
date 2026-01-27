#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool checkCapacityFitWithinDays(int days, int capacity, vector<int>& weights){
        int n = weights.size();
        long long sumOfWeights = 0;
        for(int i=0;i<n;i++)sumOfWeights += weights[i];
        int idx = 0;
        while(days && sumOfWeights){
            long long shipWeight = 0;
            while(idx<n && shipWeight<capacity){
                if(shipWeight+weights[idx]>capacity)break;
                shipWeight += weights[idx];
                sumOfWeights -= weights[idx++];
            }
            days--;
        }
        if(sumOfWeights!=0)return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        // Decide lo
        int lo = INT_MIN;
        for(int i=0;i<n;i++){
            lo = max(lo,weights[i]);
        }
        // Decide hi
        int hi = 0;
        for(int i=0;i<n;i++)hi += weights[i];
        int ans = 0;
        while(lo<=hi){
            int capacity = lo+(hi-lo)/2;
            if(checkCapacityFitWithinDays(days,capacity,weights)){
                ans = capacity;
                hi = capacity-1;
            }else lo = capacity+1;
        }
        return ans;
    }
};