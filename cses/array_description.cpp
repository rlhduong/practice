#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 1;
const int M = 101;
const int mod = 1e9 + 7;

int n, m;
int a[N];
int dp[N][M];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	if (a[0] != 0)
	{
		dp[0][a[0]] = 1;
	}
	else
	{
		for (int i = 1; i <= m; ++i)
		{
			dp[0][i] = 1;
		}
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i] != 0)
			{
				if (j == a[i])
				{
					dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j] % mod)) % mod;
					if (j != 1)
					{
						dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j - 1] % mod)) % mod;
					}

					if (j != m)
					{
						dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j + 1] % mod)) % mod;
					}
				}
				else
				{
					dp[i][j] = 0;
				}
			}
			else
			{
				dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j] % mod)) % mod;
				if (j != 1)
				{
					dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j - 1] % mod)) % mod;
				}

				if (j != m)
				{
					dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j + 1] % mod)) % mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		ans = ((ans % mod) + (dp[n - 1][i] % mod)) % mod;
	}

	cout << ans % mod << '\n';
	return 0;
}
