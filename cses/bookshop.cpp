#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1001;
const int X = 1e5 + 1;

int n, x;
int price[N];
int pages[N];
ll dp[X];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> price[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> pages[i];
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= price[i]; --j) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }

    cout << dp[x] << '\n';
    return 0;
}
