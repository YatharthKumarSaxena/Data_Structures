#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(long long trip,vector<int>& time, long long tripTime){
        long long totalTrip = 0;
        for(int i=0;i<time.size();i++){
            totalTrip += tripTime/(long long)time[i];
        }
        return trip <= totalTrip;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 1;
        long long hi = (long long)*min_element(time.begin(), time.end()) * totalTrips;
        long long ans = -1;
        while(lo<=hi){
            long long mid = lo+(hi-lo)/2;
            if(check(totalTrips,time,mid)){
                ans = mid;
                hi = mid-1;
            }else lo = mid+1;
        }
        return ans;
    }
};