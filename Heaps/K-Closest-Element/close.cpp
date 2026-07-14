#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pip;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int dis = abs(x-arr[i]);
            mp[i] = dis;
        }
        priority_queue<pip>pq;
        for(auto p: mp){
            int ele = arr[p.first];
            int dis = p.second;
            pip Pair = {dis,ele};
            if(pq.size()==k){
                int checkDis = pq.top().first;
                int checkEle = pq.top().second;
                if(checkDis == dis){
                    if(ele < checkEle){
                        pq.pop();
                        pq.push(Pair);
                    }
                }else if(dis <checkDis){
                    pq.pop();
                    pq.push(Pair);
                }
            }else pq.push(Pair);
        }
        vector<int>ans;
        while(!pq.empty()){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};