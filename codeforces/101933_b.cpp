#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	std::cin >> n;

	std::vector<std::string> seq;
	std::string line;

	for (int i = 0; i < n; ++i) {
		std::cin >> line;
		seq.emplace_back(line);
	}

	int curr = 0;
	for (int i = 0; i < n; ++i) {
		if (seq[i] == "mumble") {
			++curr;
		}
		else {
			int j = stoi(seq[i]);
			if (j != curr + 1) {
				cout << "something is fishy" << '\n';
				return 0;
			}

			++curr;
		}
	}

	cout << "makes sense" << '\n';
}s