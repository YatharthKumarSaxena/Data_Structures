#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>qu;
        queue<int>rad;
        queue<int>dire;
        int n = senate.size();
        for(int i=0;i<n;i++){
            qu.push(i);
            if(senate[i]=='R')rad.push(i);
            else dire.push(i);
        }
        while(qu.size()!=1){
            if (senate[qu.front()]=='R'){
                int i = qu.front();
                if (dire.empty()) return "Radiant";
                int idx = dire.front();
                senate[idx] = 'X';
                qu.push(i);
                dire.pop();
                rad.push(rad.front());
                rad.pop();
            } else if(senate[qu.front()]=='D') {
                int i = qu.front();
                if (rad.empty()) return "Dire";
                int idx = rad.front();
                senate[idx] = 'X';
                qu.push(i);
                rad.pop(); 
                dire.push(dire.front());
                dire.pop();
            } 
            qu.pop();
        }
        return (senate[qu.front()]=='R') ? "Radiant": "Dire";
    }
};