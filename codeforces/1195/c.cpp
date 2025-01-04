#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    ll h[2][n + 1];

    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> h[i][j];
        }  
    }

    ll dp[2][n + 1];

    dp[0][0] = 0;
    dp[1][0] = 0;

    dp[0][1] = h[0][1];
    dp[1][1] = h[1][1];

    for (int i = 2; i <= n; ++i) {
        dp[0][i] = max(h[0][i] + dp[1][i - 1], dp[0][i - 1]);
        dp[1][i] = max(h[1][i] + dp[0][i - 1], dp[1][i - 1]);
    }

    auto ans = max(dp[0][n], dp[1][n]);
    cout << ans << '\n';

    



}
