#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const int M = 2e5 + 10;
const ll INF = 1e15;

struct edge {
	int u;
	int v;
	int w;
	int id;

	bool operator<(const edge& a) const {
		return w < a.w;
	}
};

int root[N];
int subsize[N];

int find(int x);
void merge(int x, int y);

bool inMST[M];
edge edges[N];

bool seen[N];
vector<pair<int, int>> g[N];

void init();
int depth[N];
int n, m;

ll min_weight = 0;

int up[N][30];
int max_edge[N][30];

void dfs(int u, int from = 0);
int lca(int x, int y);
void kruskal();
void displayRes();

void check();
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = {u, v, w, i};
	}

	kruskal();

	int treeRoot = find(1);
	dfs(treeRoot);
	displayRes();
}

void dfs(int u, int from) {
	depth[u] = depth[from] + 1;
	for (const auto [v, w] : g[u]) {
		if (v != from) {
			up[v][0] = u;
			max_edge[v][0] = w;
			for (int j = 1; (1 << j) < n; ++j) {
				up[v][j] = up[up[v][j - 1]][j - 1];
				max_edge[v][j] = max(max_edge[v][j - 1], max_edge[up[v][j - 1]][j - 1]);
			}
			dfs(v, u);
		}
	}
}

void init() {
	for (int i = 1; i <= n; ++i) {
		seen[i] = false;
		root[i] = i;
		subsize[i] = 1;
	}
	depth[0] = 0;
}

int find(int x) {
	return root[x] == x ? x : root[x] = find(root[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (subsize[x] < subsize[y]) {
		subsize[y] += subsize[x];
		root[x] = y;
	}
	else {
		subsize[x] += subsize[y];
		root[y] = x;
	}
}

void kruskal() {
	sort(edges, edges + m);
	init();

	for (int i = 0; i < m; ++i) {
		const auto e = edges[i];

		if (find(e.u) != find(e.v)) {
			merge(e.u, e.v);
			inMST[e.id] = true;
			min_weight += e.w;
			g[e.u].emplace_back(e.v, e.w);
			g[e.v].emplace_back(e.u, e.w);
		}
	}
}

void check() {
	for (int i = 0; i < m; ++i) {
		const auto e = edges[i];
		if (!inMST[e.id]) {
			cout << lca(e.u, e.v) << '\n';
		}
	}
}

void displayRes() {
	ll res[M];
	for (int i = 0; i < m; ++i) {
		const auto e = edges[i];
		if (inMST[e.id]) {
			res[e.id] = min_weight;
		}
		else {
			res[e.id] = min_weight + e.w - lca(e.u, e.v);
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << res[i] << '\n';
	}
}

int lca(int x, int y) {
	if (depth[x] < depth[y]) {
		swap(x, y);
	}

	int max_e = max_edge[x][0];

	int d = depth[x] - depth[y];
	for (int j = 20; j >= 0; --j) {
		if (d & (1 << j)) {
			max_e = max(max_e, max_edge[x][j]);
			x = up[x][j];
		}
	}

	if (x == y) {
		return max_e;
	}

	for (int j = 20; j >= 0; --j) {
		if (up[x][j] != up[y][j]) {
			max_e = max(max_e, max(max_edge[x][j], max_edge[y][j]));
			x = up[x][j];
			y = up[y][j];
		}
	}

	return max(max_e, max(max_edge[x][0], max_edge[y][0]));
}