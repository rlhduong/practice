#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;

int n, m, k;
int trees[101];
ll dp[101][101][101];
ll p[101][101];
int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> trees[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> p[i][j];
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int a = 0; a <= k; ++a) {
				dp[i][j][a] = INF;
			}
		}
	}

	if (trees[1] == 0) {
		for (int j = 1; j <= m; ++j) {
			dp[1][j][1] = p[1][j];
		}
	}
	else {
		dp[1][trees[1]][1] = 0;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int a = 1; a <= k; ++a) {
				if (trees[i] == 0) {
					dp[i][j][a] = min(dp[i][j][a], dp[i - 1][j][a] + p[i][j]);

					for (int colour = 1; colour <= m; ++colour) {
						if (colour != j) {
							dp[i][j][a] = min(dp[i][j][a], dp[i - 1][colour][a - 1] + p[i][j]);
						}
					}
				}
				else {
					dp[i][trees[i]][a] = min(dp[i][trees[i]][a], dp[i - 1][trees[i]][a]);
					for (int colour = 1; colour <= m; ++colour) {
						if (colour != trees[i]) {
							dp[i][trees[i]][a] = min(dp[i][trees[i]][a], dp[i - 1][colour][a - 1]);
						}
					}

					for (int colour = 1; colour <= m; ++colour) {
						if (colour != trees[i]) {
							dp[i][colour][a] = INF;
						}
					}
				}
			}
		}
	}
	ll ans = INF;
	for (int j = 1; j <= m; ++j) {
		ans = min(ans, dp[n][j][k]);
	}
	if (ans >= INF) {
		ans = -1;
	}
	cout << ans << '\n';
}