#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;
const int mod = 1e9 + 7;
;
const int N = 1e6;
const int M = 1e6;

struct state {
	int dist;
	int v;
};

int n, m, k;
int t = 1;

bool seen[N];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> edges[N];

vector<string> grid;

pair<int, int> start;

int q[N];
string ans;

void in() {
	cin >> n >> m >> k;
	ans = string(m, '1');
	fill(seen, seen + n + 1, false);

	for (int i = 0; i < m; ++i) {
		cin >> q[i];
	}

	int a;
	for (int i = 0; i < k; ++i) {
		cin >> a;
		seen[a] = true;
	}
}

void solve() {
	if (k == n) {
		ans = string(m, '1');
		cout << ans << '\n';
		return;
	}

	if (k < n - 1) {
		ans = string(m, '0');
		cout << ans << '\n';
		return;
	}

	for (int i = 0; i < m; ++i) {
		if (!seen[q[i]]) {
			ans[i] = '1';
		}
		else {
			ans[i] = '0';
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while (T-- > 0) {
		in();
		solve();
	}
}