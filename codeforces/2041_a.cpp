#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;
const int mod = 1e9 + 7;;
const int N = 1e6;
const int M = 1e6;

int n,m,k;

bool seen[N];

void solve() {
    
}

int main() {
    cin.tie(nullptr);
	cin.sync_with_stdio(false);

    for (int i = 0;  i < 4;++i) {
        int a;
        cin >> a;

        seen[a] = true;
    }

    for (int i = 1; i <= 5; ++i) {
        if (!seen[i]) {
            cout << i << '\n';
            return 0;
        }
    }
}