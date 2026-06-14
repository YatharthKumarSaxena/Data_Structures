#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int bookSize = bookings.size();
        vector<int>ans(n,0);
        for(int i=0;i<bookSize;i++){
            int startIdx = bookings[i][0]-1;
            int endIdx = bookings[i][1]-1;
            for(int j=startIdx;j<=endIdx;j++){
                ans[j] += bookings[i][2];
            }
        }
        return ans;
    }
};