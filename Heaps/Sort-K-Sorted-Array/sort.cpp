#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans(n,0);
        int j=0;
        for(int i=0;i<n;i++){
            if(pq.size()>k){
                ans[j] = pq.top();
                pq.pop();
                j++;
            }
            pq.push(arr[i]);
        }
        while(pq.size()){
            ans[j] = pq.top();
            pq.pop();
            j++;
        }
        for(int i=0;i<n;i++){
            arr[i] = ans[i];
        }
    }
};