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

int n,m,k,t;
bool seen[N];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int a,b;
void in() {
    cin >> a >> b;
}

void solve() {
    if (a >= b) {
        printf("%d\n", a);
    }
    else {
        int x = 2 * a - b;
        printf("%d\n", max(0, x));
    }
}

int main() {
    cin.tie(nullptr);
	cin.sync_with_stdio(false);
    cin >> t;
    while (t-- > 0) {
        in();
        solve();
    }
}