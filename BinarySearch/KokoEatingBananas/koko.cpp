#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool checkCapacityFitWithinHours(int hours, int capacity, vector<int> piles){
        int n = piles.size();
        long long sumOfPiles = 0;
        int speed = 0;
        for(int i=0;i<n;i++){
            if(piles[i]<capacity)speed++;
            else if(piles[i]%capacity==0)speed += piles[i]/capacity;
            else speed += piles[i]/capacity + 1;
        }
        return speed <= hours;
    }
    int minEatingSpeed(vector<int>& piles, int hours) {
        int n = piles.size();
        // Decide hi
        int hi = INT_MIN;
        for(int i=0;i<n;i++){
            hi = max(hi,piles[i]);
        }
        // Decide lo
        long long lo = 0;
        for(int i=0;i<n;i++)lo += piles[i];
        lo /= hours;
        if(lo==0)lo = 1;
        int ans = 0;
        while(lo<=hi){
            int capacity = lo+(hi-lo)/2;
            if(checkCapacityFitWithinHours(hours,capacity,piles)){
                ans = capacity;
                hi = capacity-1;
            }else lo = capacity+1;
        }
        return ans;
    }
};