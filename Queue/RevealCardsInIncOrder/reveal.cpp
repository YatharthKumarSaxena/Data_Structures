#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>qu;
        sort(deck.begin(),deck.end());
        int n = deck.size();
        for(int i=0;i<n;i++) qu.push(i);
        vector<int>ans(n,0);
        int count = 0;
        while(qu.size()){
            int idx = qu.front();
            ans[idx] = deck[count];
            qu.pop();
            if(qu.size()){
                 qu.push(qu.front());
                 qu.pop();
            } 
            count += 1;
        }
        return ans;
    }
};