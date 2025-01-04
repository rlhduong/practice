#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll k;
    cin >> n >> k;

    string s, t;
    cin >> s >> t;

    ll curr = 1;
    ll ans = 0;

    for  (int i = 0; i < n; ++i) {
        curr *= 2;
        if  (s[i] == 'b') {
            --curr;
        }

        if (t[i] == 'a') {
            --curr;
        }

        if (curr > k) {
            ans += k;
            curr = k + 1;
        }
        else {
            ans += curr;
        }

    }

    cout << ans << '\n';
}