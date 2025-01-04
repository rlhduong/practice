#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e12;

int n, k;
string router;

ll tree[1 << 22];
ll query(int ql, int qr, int i = 1, int l = 0, int r = n);
void update(int p, ll v, int i = 1, int cL = 0, int cR = n);
void debug(int i = 1, int cL = 0, int cR = n);
int main() {
	cin >> n >> k >> router;
	vector<pair<int, int>> segments[n + 1];

	for (int i = 0; i < n; ++i) {
		int c = i + 1;

		if (router[i] == '1') {
			int e = min(n - 1, i + k);
			segments[e].emplace_back(max(0, i - k), c);
			segments[i].emplace_back(max(0, i - k), c);
		}

		segments[i].emplace_back(i, c);
	}

	for (int i = 0; i < n; ++i)
		update(i, INF);

	ll dp[n + 1];
	for (int i = 0; i < n; ++i) {
		dp[i] = INF;
		for (auto seg : segments[i]) {
			ll prev = seg.first == 0 ? 0 : query(seg.first - 1, i);
			dp[i] = min(dp[i], prev + seg.second);
		}
		update(i, dp[i]);
	}
	cout << dp[n - 1] << '\n';
}

ll query(int ql, int qr, int i, int l, int r) {
	if (ql == l and qr == r) {
		return tree[i];
	}

	int mid = (l + r) / 2;
	ll m = INF;
	if (ql < mid) {
		m = query(ql, min(qr, mid), i * 2, l, mid);
	}

	if (qr > mid) {
		m = min(m, query(max(ql, mid), qr, i * 2 + 1, mid, r));
	}

	return m;
}

void update(int p, ll v, int i, int cL, int cR) {
	if (cR - cL == 1) {
		tree[i] = v;
		return;
	}
	int mid = (cL + cR) / 2;
	if (p < mid)
		update(p, v, i * 2, cL, mid);
	else
		update(p, v, i * 2 + 1, mid, cR);
	tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

void debug(int i, int cL, int cR) {
	cerr << "tree[" << cL << "," << cR << ") = " << tree[i] << '\n';
	if (cR - cL > 1) {
		int mid = (cL + cR) / 2;
		debug(i * 2, cL, mid);
		debug(i * 2 + 1, mid, cR);
	}
}