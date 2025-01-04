#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
using pli = pair<ll,int>;

struct node {
    int v;
    ll dis;
    bool train;
    bool operator<(const node& a) const {
        if (dis != a.dis) {
            return dis < a.dis;
        }
        
        if (v != a.v) {
            return v < a.v;
        }

        return train ? false : true;
    }
};

int n, m, k;
bool train[N];
bool rm[N];
bool seen[N];
ll dis[N];
vector<pair<int,ll>> edges[N];
set<node> s;
void dijkstra();
int ans = 0;

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int u , v;
        ll d;
        cin >> u >> v >> d;
        edges[u].push_back({v,d});
        edges[v].push_back({u,d});
    }

    for (int i = 0; i < k; ++i) {
        int v;
        ll d;
        cin >> v >> d;
        s.insert({v,d,true});
        train[v] = true;
    }

    dijkstra();
    cout << k - ans << '\n';
}

void dijkstra() {
    fill(seen, seen + N, false);
    fill(train, train + N, false);
    s.insert({1,0,false});
    while (!s.empty()) {
        auto [v, dist, isTrain] = *s.begin();
        s.erase(s.begin());

        if (seen[v]) {
            continue;
        }

        dis[v] = dist;
        seen[v] = true;
        if (isTrain) {
            ++ans;
        }

        for (auto [next, w] : edges[v]) {
            if (!seen[next]) {
                s.insert({next, dist + w, false});
            }
        }
    }
}