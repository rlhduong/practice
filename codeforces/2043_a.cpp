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
ll n;
int m, k;
int t = 1;

bool seen[N];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> edges[N];

vector<string> grid;

pair<int, int> start;

void in() {
	cin >> n;
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

ll pow2(ll x, ll n) {
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		ans *= x;
	}
	return ans;
}

void solve() {
	auto l = static_cast<int>(log(n) / log(4));
    if (pow(4, l) > n) {
        --l;
    }
	cout << pow(2, l, mod) << '\n';
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