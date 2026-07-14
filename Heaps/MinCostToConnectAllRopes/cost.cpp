#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        int ans = 0;
        while(pq.size()>1){
            int f = pq.top();
            pq.pop();
            if(pq.size()){
                int s = pq.top();
                pq.pop();
                pq.push(f+s);
                ans += (f+s);
            }
        }
        return ans;
    }
};