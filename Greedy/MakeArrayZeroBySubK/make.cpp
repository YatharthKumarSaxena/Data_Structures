#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0)pq.push(nums[i]);
        }
        int ops = 0;
        while(!pq.empty()){
            int ele = pq.top();
            pq.pop();
            vector<int>temp;
            while(!pq.empty()){
                int other = pq.top();
                pq.pop();
                if(other-ele)temp.push_back(other-ele);
            }
            int t = temp.size();
            for(int j=0;j<t;j++){
                pq.push(temp[j]);
            }
            ops++;
        }
        return ops;
    }
};