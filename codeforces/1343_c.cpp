#include <bits/stdc++.h>
using namespace std;

bool get_sign(int num);
int main() {
	int loop;
	cin >> loop;

	for (int j = 0; j < loop; ++j) {
		int n;
		cin >> n;
		vector<long long> seq;
		long long temp;
		bool sign;
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			if (i == 0) {
				sign = get_sign(temp);
				seq.push_back(temp);
				continue;
			}

			if (sign == get_sign(temp)) {
				seq.back() = max(seq.back(), temp);
			}
			else {
				seq.push_back(temp);
				sign = !sign;
			}
		}

		long long sum = 0;
		for (const int& i : seq) {
			sum += i;
		}
		std::cout << sum << '\n';
	}
}

bool get_sign(int num) {
	return num < 0;
}
