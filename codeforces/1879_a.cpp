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
pair<int, int> aths[100];

void in() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> aths[i].first;
		cin >> aths[i].second;
	}
}

void solve() {
    int w = aths[0].first;
    int e = aths[0].second;

    for (int i = 1; i < n; ++i) {
        if (aths[i].first >= w && aths[i].second >= e) {
            cout << "-1\n";
            return;
        }
    }
    cout << w << '\n';
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