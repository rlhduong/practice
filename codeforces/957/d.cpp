#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;

	int u[n + 1];
	int m[n + 1];

	u[0] = 0;
	m[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> u[i];
		m[i] = max(m[i - 1], u[i] + 1);
	}

	for (int i = n; i >= 1; --i) {
		if (m[i] > m[i - 1] + 1) {
			m[i - 1] = m[i] - 1;
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += m[i] - u[i] - 1;
	}

	cout << ans << '\n';
}