#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

// Path Compression
int findGroupLeader(int ele, vector<int> &par)
{ // Return the Group Element of the Element ele present in a group
    return par[ele] = ((ele == par[ele]) ? ele : findGroupLeader(par[ele], par));
}
void unionGroups(int eleA, int eleB, vector<int> &par, vector<int> &rank)
{ // Combine the Group Elements of B into Group Elements of A
    int parA = findGroupLeader(eleA, par);
    int parB = findGroupLeader(eleB, par);
    if (parA == parB)
        return;
    if (rank[parA] >= rank[parB])
    {
        par[parB] = parA;
        rank[parA]++;
    }
    else
    {
        par[parA] = parB;
        rank[parB]++;
    }
    return;
}

int minimumCost(int n, vector<vector<int>> &connections)
{
    vector<int> par(n + 1);
    vector<int> rank(n + 1);
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
        rank[i] = 1;
    }
    vector<tuple<int, int, int>> Edge;
    for (int i = 0; i < connections.size(); i++)
    {
        tuple<int, int, int> t = {connections[i][2], connections[i][0], connections[i][1]};
        Edge.push_back(t);
    }
    sort(Edge.begin(), Edge.end());
    int loopCount = 0;
    int cost = 0;
    for (auto &edge : Edge)
    {
        int weight = std::get<0>(edge);
        int u = std::get<1>(edge);
        int v = std::get<2>(edge);
        if (findGroupLeader(u, par) != findGroupLeader(v, par))
        {
            unionGroups(u, v, par, rank);
            cost += weight;
            loopCount++;
            if (loopCount == n - 1)return cost;
        }
    }
    return -1;
}

int main()
{
    // Test Case 1
    vector<vector<int>> connections1 = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    int n1 = 3;
    int result1 = minimumCost(n1, connections1);
    cout << "Test Case 1 - Minimum cost: " << result1 << endl;

    // Test Case 2
    vector<vector<int>> connections2 = {{1, 2, 1}, {2, 3, 2}, {1, 3, 3}};
    int n2 = 3;
    int result2 = minimumCost(n2, connections2);
    cout << "Test Case 2 - Minimum cost: " << result2 << endl;

    // Test Case 3 (Disconnected Graph)
    vector<vector<int>> connections3 = {{1, 2, 1}, {3, 4, 2}};
    int n3 = 4;
    int result3 = minimumCost(n3, connections3);
    cout << "Test Case 3 - Minimum cost: " << result3 << endl;

    // Test Case 4 (Multiple Edges with Same Weight)
    vector<vector<int>> connections4 = {{1, 2, 1}, {2, 3, 1}, {1, 3, 1}, {3, 4, 1}};
    int n4 = 4;
    int result4 = minimumCost(n4, connections4);
    cout << "Test Case 4 - Minimum cost: " << result4 << endl;

    return 0;
}