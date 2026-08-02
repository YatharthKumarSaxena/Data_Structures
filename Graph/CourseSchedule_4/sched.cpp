#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>>mp;
        int totalDep = prerequisites.size();
        for(int k=0;k<numCourses;k++){
            for(int i=0;i<totalDep;i++){
                int key = prerequisites[i][0];
                int val = prerequisites[i][1];
                mp[key].insert(val);
                if(mp.find(val)!=mp.end()){
                    for(int ele: mp[val])mp[key].insert(ele);
                }
            }
        }

        int ansSize = queries.size();
        vector<bool>ans(ansSize,false);
        for(int i=0;i<ansSize;i++){
            int key = queries[i][0];
            int val = queries[i][1];
            if(mp[key].count(val)){
                ans[i] = true;
            }
        }

        return ans;
    }
};