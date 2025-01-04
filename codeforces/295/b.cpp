#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;

int n;
const int N = 510;

ll dist[N][N];
int queries[N];
bool seen[N];
ll floyd(int added);

ll ans[N];

int main() {
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            dist[u][v] = INF;
        }
    }

    for (int i = 1; i <= n; ++i) {
        seen[i] = false;
    }

    cin >> n;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            cin >> dist[u][v];
        }
    }

    for (int i = 0; i < n;++i) {
        cin >> queries[i];
    }

    for (int i = n -1; i >=0 ;--i) {
        ans[i] = floyd(queries[i]);
    }

    for (int i = 0;  i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

ll floyd(int added) {
    seen[added] = true;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            dist[u][v] = min(dist[u][v], dist[u][added] + dist[added][v]);
    ll ans = 0;
    for (int u = 1; u <= n; ++u) if (seen[u])
        for (int v = 1; v<= n; ++ v) if (seen[v]) {
            ans += dist[u][v];
        }

    return ans;
}