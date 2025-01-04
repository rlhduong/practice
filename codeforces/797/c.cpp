#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct CompareChar {
	bool operator()(pair<char, int> a, pair<char, int> b) {
		if (a.first != b.first) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

int main() {
	priority_queue<pair<char, int>, vector<pair<char, int>>, CompareChar> pq;
	stack<char> t;

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); ++i) {
		pq.push(make_pair(input[i], i));
	}

	int curr = 0;
	while (not pq.empty()) {
		const char c = pq.top().first;
		const int pos = pq.top().second;
		pq.pop();

		if (pos < curr) {
			continue;
		}

		if (t.empty()) {
			cout << c;

			for (int i = curr; i < pos; ++i) {
				t.push(input[i]);
			}

			curr = pos + 1;
		}
		else {
			if (c < t.top()) {
				cout << c;

				for (int i = curr; i < pos; ++i) {
					t.push(input[i]);
				}

				curr = pos + 1;
			}
			else {
				while (not t.empty() and c >= t.top()) {
					cout << t.top();
					t.pop();
				}

				for (int i = curr; i < pos; ++i) {
					t.push(input[i]);
				}

				cout << c;
				curr = pos + 1;
			}
		}
	}

	while (not t.empty()) {
		cout << t.top();
		t.pop();
	}
}