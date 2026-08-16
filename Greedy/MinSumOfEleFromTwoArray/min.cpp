#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    typedef pair<int,int>pip;
    int minSum(vector<int>& arr1, vector<int>& arr2) {
        // code here
        priority_queue<pip,vector<pip>,greater<pip>>pq1,pq2;
        int n1 = arr1.size();
        int n2 = arr2.size();
        for(int i=0;i<n1;i++){
            pq1.push({arr1[i],i});
        }
        for(int i=0;i<n2;i++){
            pq2.push({arr2[i],i});
        }
        while(pq1.size() && pq2.size()){
            pip pair1 = pq1.top();
            pq1.pop();
            pip pair2 = pq2.top();
            pq2.pop();
            int idx1 = pair1.second;
            int idx2 = pair2.second;
            int ele1 = pair1.first;
            int ele2 = pair2.first;
            if(idx1!=idx2){
                return ele1+ele2;
            }
            // Same index
            if (pq1.empty()) {
                pq2.push(pair2);
                continue;
            }
            
            if (pq2.empty()) {
                pq1.push(pair1);
                continue;
            }
            
            pip next1 = pq1.top();
            pip next2 = pq2.top();
            
            int option1 = next1.first + pair2.first;
            int option2 = pair1.first + next2.first;
            
            if (option1 < option2) {
                // arr1 ka next pair lena better hai
                pq2.push(pair2);
            } else {
                // arr2 ka next pair lena better hai
                pq1.push(pair1);
            }
        }
        return 0;
    }
};
