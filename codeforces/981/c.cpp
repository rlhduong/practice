#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = std::numeric_limits<long long>::max();
int n;
vector<int> edges[100001];
bool seen[1000001];
void dfs(int& start, int u);
int main() {
    cin  >> n;
    for(int i = 0; i < n - 1; ++i) {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        seen[i] =  false;
    }

    int total = 0;
    int intersect = 0;
    int start = 0;

    for (int i = 0; i <= n; ++i) {
        if (edges[i].size() == 1) {
            start = i;
        }

        if (edges[i].size() > 2) {
            intersect = i;
            ++total;
        }
    }

    if (total > 1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";

    if (total == 0) {
        cout << 1 << '\n';
        dfs(start, start);
    }
    else {
        cout << edges[intersect].size() << '\n';
        dfs(intersect, intersect);
    }

    // cout << intersect << '\n';
}

void dfs(int& start, int u) {
    if (seen[u]) {
        return;
    }
    seen[u] = true;
    if (edges[u].size() == 1 and u != start) {
        cout << start << ' ' << u << '\n';
    }
    for (int& v : edges[u]) {
        dfs(start, v);
    }
}