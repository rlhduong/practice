#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;
const int mod = 1e9 + 7;;
const int N = 1e4;
const int M = 1e4;

pair<int,int> s;
pair<int,int> e;
bool found = false;

/*

struct state {
    int dist;
    int r;
    int c;
    int dir;
    int step;
};

using node = tuple<int,int,int,int>;

set<node> ss;

int n,m,k;
char grid[N][M];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool valid(int r, int c) {
    if (r < 0 || r >= n) {
        return false;
    }

    if (c < 0 || c >= m) {
        return false;
    }

    if (grid[r][c] == '#') {
        return false;
    }

    return true;
}

void bfs() {
    queue<state> q;
    q.push({0,s.first, s.second, 0, 0});

    while (!q.empty()) {
        auto [d, r, c, dir, step] = q.front();
        q.pop();

        if (r == e.first and c == e.second) {
            found = true;
            cout << d << '\n';
            return;
        }
        ss.insert(node{r,c,dir,step});
        for (int i = 0; i < 4; ++i) {
            int new_r = r + dy[i];
            int new_c = c + dx[i];
            int new_dir = i + 1;
            int new_step = new_dir == dir? step + 1: 1;

            if (!valid(new_r, new_c) || new_step > 3) {
                continue;
            }
            if (ss.find(node{new_r, new_c, new_dir, new_step}) == ss.end()) {
                q.push({d + 1, new_r, new_c, new_dir, new_step});
            }
        }

    }
}

void solve() {
    bfs();
}

int main() {
    cin.tie(nullptr);
	cin.sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0;  j < m; ++j) {
            cin >> grid[i][j];

            if (grid[i][j] == 'S') {
                s.first = i;
                s.second = j;
            }
            else if (grid[i][j] == 'T') {
                e.first = i;
                e.second = j;
            }
        }
    }
    solve();

    if (!found) {
        cout << "-1\n";
    }
}