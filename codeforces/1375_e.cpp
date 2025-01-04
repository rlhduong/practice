#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;

int main() {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;

	ll a[n];
	vector<p> pairs;
	vector<p> ans;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) {
				pairs.push_back({i, j});
			}
		}
	}

	sort(pairs.begin(), pairs.end(), [&](const p& b, const p& c) {
		if (b.second != c.second) {
			return b.second > c.second;
		}

		if (a[b.first] != a[c.first]) {
			return a[b.first] < a[c.first];
		}

		return b.first < c.first;
	});

	for (const auto& pair : pairs) {
		int u = pair.first;
		int v = pair.second;
		ans.push_back(pair);
		swap(a[u], a[v]);
	}

	cout << ans.size() << '\n';
	for (const auto& pair : ans) {
		cout << pair.first + 1 << ' ' << pair.second + 1 << '\n';
	}

	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
}