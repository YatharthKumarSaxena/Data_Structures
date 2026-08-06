#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    const int INF = 1e9;
    vector<int> dp(x + 1, INF);

    // Base Case
    dp[0] = 0;

    // Write DP Logic Here
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j] >= 0 && dp[i - coins[j]] != INF){
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }


    // Output
    if (dp[x] == INF)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;

    return 0;
}