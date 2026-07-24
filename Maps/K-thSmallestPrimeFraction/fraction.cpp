#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    typedef pair<float,pair<int,int>> pfp;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pfp>fractions;
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                fractions.push_back({1.0 * arr[i]/arr[j],{arr[i],arr[j]}});
            }
        }
        int totalFractions = fractions.size();
        priority_queue<pfp>pq;
        for(int i=0;i<totalFractions;i++){
            pq.push(fractions[i]);
            while(pq.size()>k)pq.pop();
        }
        vector<int>ans = {pq.top().second.first,pq.top().second.second};
        return ans;
    }
};