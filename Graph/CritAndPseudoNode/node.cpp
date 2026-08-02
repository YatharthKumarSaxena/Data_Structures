#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    vector<int> parent, Rank;

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    bool Union(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);

        if (pa == pb) return false;

        if (Rank[pa] < Rank[pb])
            swap(pa, pb);

        parent[pb] = pa;

        if (Rank[pa] == Rank[pb])
            Rank[pa]++;

        return true;
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {

        parent.resize(n);
        Rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int weight = 0;
        int cnt = 0;

        if (force != -1) {
            Union(edges[force][0], edges[force][1]);
            weight += edges[force][2];
            cnt++;
        }

        for (int i = 0; i < edges.size(); i++) {

            if (i == skip)
                continue;

            if (Union(edges[i][0], edges[i][1])) {
                weight += edges[i][2];
                cnt++;
            }
        }

        if (cnt != n - 1)
            return INT_MAX;

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(), cmp);

        int baseWeight = kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < edges.size(); i++) {

            if (kruskal(n, edges, i, -1) > baseWeight) {
                critical.push_back(edges[i][3]);
            }
            else if (kruskal(n, edges, -1, i) == baseWeight) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};