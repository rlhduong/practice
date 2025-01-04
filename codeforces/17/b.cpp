#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e6 + 2;

int n, m;
int q[1005];
vector<pair<int, int>> edges[1005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> q[i];
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[v].push_back({u, w});
	}
	ll ans = 0;
	int total = 0;

	for (int i = 1; i <= n; ++i) {
		if (edges[i].size() == 0) {
			++total;
		}
		else {
			int cost = INF;

			for (const auto e : edges[i]) {
				cost = min(cost, e.second);
			}
			ans += cost;
		}
	}

	if (total > 1) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
}
