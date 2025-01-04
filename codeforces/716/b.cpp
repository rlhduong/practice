#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	string input;
	cin >> input;

	if (input.size() < 26) {
		cout << -1;
		return 0;
	}

	unordered_map<char, int> seen;
	int curr = 0;
	int counter = 0;
	int i = 0;
	bool found = false;
	while (i < input.length()) {
		if (input[i] == '?') {
			++counter;

			if (counter == 26) {
				found = true;
				break;
			}
		}
		else {
			if (seen.contains(input[i])) {
				for (int j = curr; j < seen[input[i]]; ++j) {
					seen.erase(input[j]);
				}
				curr = seen[input[i]] + 1;
				seen[input[i]] = i;
				counter = i - curr + 1;
			}
			else {
				++counter;
				seen[input[i]] = i;

				if (counter == 26) {
					found = true;
					break;
				}
			}
		}
		++i;
	}

	if (not found) {
		cout << -1;
		return 0;
	}

	unordered_set<char> missing;

	for (int j = 65; j < 91; ++j) {
		char c = static_cast<char>(j);

		if (not seen.contains(c)) {
			missing.insert(c);
		}
	}

	for (int j = curr; j <= i; ++j) {
		if (input[j] == '?') {
			char c = *missing.begin();
			missing.erase(c);
			input[j] = c;
		}
	}

	for (int j = 0; j < input.length(); ++j) {
		if (input[j] == '?') {
			input[j] = 'A';
		}
	}

	cout << input;
}