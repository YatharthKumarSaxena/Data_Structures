#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> findDigits(int num){
    vector<int>ans;
    while(num){
        ans.push_back(num%10);
        num /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input
    int n;
    cin >> n;

    // Write your logic here
    vector<int>dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=9;i++){
        dp[i] = 1;
    }
    for(int i=10;i<=n;i++){
        vector<int>digits = findDigits(i);
        for(int j=0;j<digits.size();j++){
            if(digits[j] != 0 && dp[i-digits[j]] != INT_MAX){
                dp[i] = min(dp[i], dp[i-digits[j]] + 1);
            }
        }
    }

    // Output
    cout << dp[n] << endl;

    return 0;
}