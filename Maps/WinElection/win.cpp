#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
  public:

    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n) {
        // Your code here
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        string ans = arr[0];
        int maxVote = INT_MIN;
        for(auto p: mp){
            string ele = p.first;
            int votes = p.second;
            if(votes > maxVote){
                maxVote = votes;
                ans = ele;
            }
            else if(votes == maxVote){
                if(ele<ans){
                    ans = ele;
                }
            }
        }
        return {ans,to_string(maxVote)};
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
    }
};