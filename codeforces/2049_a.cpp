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

int a[N];

void in() {
	bool c0 = true;
	bool c1 = false;
	bool c2 = false;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > 0) {
			c0 = false;
		}
	}

    if (c0) {
        cout << "0\n";
        return;
    }

	for (int i = 1; i < n - 1; ++i) {
		if (c1 == false and a[i] == 0 and a[i - 1] > 0) {
			c1 = true;
		}

		if (c1 and a[i] == 0 and a[i + 1] > 0) {
			c2 = true;
			break;
		}
	}

	if (c2) {
		cout << "2\n";
	}
	else {
		cout << "1\n";
	}
}

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