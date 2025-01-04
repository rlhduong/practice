#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int n, m, k;
int a[19];
int c[19][19];
ll dp[1 << 18 + 1][19];
int popc(int x);
int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	while (k-- > 0) {
		int d1, d2, ci;
		cin >> d1 >> d2 >> ci;
		c[d1 - 1][d2 - 1] = ci;
	}

    for (int set = 0; set < (1 << n); ++set) {
        for (int i = 0; i < n; ++i) {
            if (set == (1 << i)) {
                dp[set][i] = a[i];
            }
            else {
                dp[set][i] = 0;
            }
        }
    }

	ll ans = 0;
	for (int set = 0; set < (1 << n); ++set) {
		for (int curr = 0; curr < n; ++curr) {
			if (set & (1 << curr)) {
				for (int next = 0; next < n; ++next) {
					if (!(set & (1 << next))) {
						dp[set | (1 << next)][next] =
						    max(dp[set | (1 << next)][next], dp[set][curr] + a[next] + c[curr][next]);
					}
				}
			}
		}
	}

	for (int set = 0; set < (1 << n); ++set) {
		if (popc(set) == m) {
			for (int i = 0; i < n; ++i) {
				ans = max(ans, dp[set][i]);
			}
		}
	}

	cout << ans << '\n';
}

int popc(int x) {
	int count = 0;
	while (x) {
		count += x & 1;
		x >>= 1;
	}
	return count;
}