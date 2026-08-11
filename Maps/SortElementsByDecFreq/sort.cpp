#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    typedef pair<int,int> pip;
    struct Compare {
        bool operator()(const pip& a, const pip& b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        vector<int> ans;
        unordered_map<int,int>mp;
        priority_queue<pip,vector<pip>,Compare>pq;
        int n = arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto Pair: mp){
            int ele = Pair.first;
            int count = Pair.second;
            pip p = {count,ele};
            pq.push(p);
        }
        while(pq.size()){
            pip Pair = pq.top();
            pq.pop();
            int ele = Pair.second;
            while(mp[ele]){
                mp[ele]--;
                ans.push_back(ele);
            }
            mp.erase(ele);
        }
        return ans;
    }
};