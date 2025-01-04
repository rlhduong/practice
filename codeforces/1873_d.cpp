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

int n, m, k;
int t = 1;

bool seen[N];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> edges[N];

string cells;
void in() {
    cin >> n >> k;
    cin >> cells;
}

void solve() {
    int ans = 0;
    int i = 0;
    while (i < n) {
        if (cells[i] == 'W') {
            ++i;
        }
        else {
            i += k;
            ++ ans;
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