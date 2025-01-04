#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int n, k;

bool seen[2][N];
char wall[2][N];

struct nin {
	int height;
	int wall;
	int level;
};
queue<nin> q;

bool valid(const nin& ninja);

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s%s", wall[0] + 1, wall[1] + 1);

	q.push({1, 0, 0});
	seen[0][1] = true;

	while (!q.empty()) {
		auto [h, w, l] = q.front();
		q.pop();

		nin up = {h + 1, w, l + 1};
		nin down = {h - 1, w, l + 1};
		nin side = {h + k, (w + 1) % 2, l + 1};

		if (up.height > n || side.height > n) {
			printf("YES\n");
			return 0;
		}

		if (valid(up)) {
			q.push(up);
		}

		if (valid(down)) {
			q.push(down);
		}

		if (valid(side)) {
			q.push(side);
		}
	}

	printf("NO\n");
}

bool valid(const nin& ninja) {
	if (seen[ninja.wall][ninja.height] || wall[ninja.wall][ninja.height] == 'X' || ninja.height <= ninja.level) {
		return false;
	}
	seen[ninja.wall][ninja.height] = true;
	return true;
}
