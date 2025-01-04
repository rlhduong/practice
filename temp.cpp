#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;
const int mod = 1e9 + 7;
const int N = 1e6;
const int M = 1e6;

struct state {
	int dist;
	int v;
};

int n, m, k, s, t;

bool seen[N];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> edges[N];
ll pow(ll x, ll n, int m);
void in() {}

void solve() {}

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

ll pow(ll x, ll n, int m) {
	if (n == 0)
		return 1;
	ll a = pow(x, n / 2, m);
	a = a * a % m;
	if (n % 2 == 1)
		a = a * x % m;
	return a;
}