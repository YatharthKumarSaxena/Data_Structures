#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n = stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int firstStone = pq.top();
            pq.pop();
            int secondStone = pq.top();
            pq.pop();
            int diffStone = abs(firstStone-secondStone);
            if(diffStone){
                pq.push(diffStone);
            }
            if(pq.size()==0)return 0;
        }
        return pq.top();
    }
};