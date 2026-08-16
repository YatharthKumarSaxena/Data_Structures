#include <bits/stdc++.h>
using namespace  std;


class Solution {
  public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();

        vector<pair<int, int>> jobs;

        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        // parent[x] = latest available slot <= x
        parent.resize(maxDeadline + 1);

        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int count = 0;
        int totalProfit = 0;

        for (auto job : jobs) {
            int p = job.first;
            int d = job.second;

            int slot = find(d);

            if (slot > 0) {
                count++;
                totalProfit += p;

                // Slot is now occupied.
                // Next time find(slot), go to slot-1.
                parent[slot] = find(slot - 1);
            }
        }

        return {count, totalProfit};

    }
};
