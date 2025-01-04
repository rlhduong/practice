#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;
const int mod = 1e9 + 7;;
const int N = 1e6;
const int M = 1e6;

struct state {
    int dist;
    int v;
};

int n,m,k;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void in() {
    cin >> n >> m;
}

void solve() {

    if (n == m) {
        cout << "1\n";
        cout << n << '\n';
        return;
    }
    cout << "3\n";
    cout << m << ' ' << m << ' ' << n * 3 - 2 * m << '\n';
}

int main() {
    cin.tie(nullptr);
	cin.sync_with_stdio(false);
    in();
    solve();
}