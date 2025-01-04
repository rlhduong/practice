#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll a1 = (sqrt(1 + 8 * a) - 1) / 2;
	ll a2 = (a1 * (a1 + 1)) / 2;
	if (a2 != a) {
		cout << "impossible\n";
		return 0;
	}

	ll d1 = (sqrt(1 + 8 * d) - 1) / 2;
	ll d2 = (d1 * (d1 + 1)) / 2;
	if (d2 != d) {
		cout << "impossible\n";
		return 0;
	}

	if (a == 0 and b == 0 and c == 0 and d == 0) {
		cout << "0\n";
		return 0;
	}

	if (a == 0 and d == 0) {
		if (b == 1 and c == 0) {
			cout << "01\n";
			return 0;
		}
		else if (b == 0 and c == 1) {
			cout << "10\n";
			return 0;
		}
		else {
			cout << "impossible\n";
			return 0;
		}
	}

	if (b == 0 and c == 0) {
		if (a != 0 and d == 0) {
			for (int i = 0; i <= a1; ++i) {
				cout << 0;
			}
			cout << '\n';
			return 0;
		}
		else if (a == 0 and d != 0) {
			for (int i = 0; i <= d1; ++i) {
				cout << 1;
			}
			cout << '\n';
			return 0;
		}
		else {
			cout << "impossible\n";
			return 0;
		}
	}

	ll t0 = a1 + 1;
	ll t1 = d1 + 1;

	if (b + c != t0 * t1) {
		cout << "impossible\n";
		return 0;
	}

	ll f0 = b / t1;
	ll b0 = c / t1;
	ll m0 = t0 - f0 - b0;

	ll b_rem = b - (f0 * t1);
	ll b1 = m0 == 0 ? t1 : b_rem / m0;
	ll f1 = t1 - b1;

	for (int i = 0; i < f0; ++i) {
		cout << 0;
	}

	for (int i = 0; i < f1; ++i) {
		cout << 1;
	}

	for (int i = 0; i < m0; ++i) {
		cout << 0;
	}

	for (int i = 0; i < b1; ++i) {
		cout << 1;
	}

	for (int i = 0; i < b0; ++i) {
		cout << 0;
	}

	cout << '\n';
}