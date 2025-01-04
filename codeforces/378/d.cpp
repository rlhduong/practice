#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct st {
	int ability;
	int pass;
	int pos;
};

struct cmp {
	bool operator()(const st& a, const st& b) {
		if (a.pass != b.pass) {
			return a.pass > b.pass;
		}
		return a.pos > b.pos;
	}
};

int n, m, s;
int res[100001];
st students[100001];
int temp[100001];
pair<int, int> bugs[100001];

bool can_do_within(const int& days);

bool haha() {
	return true;
}

int main() {
	cin >> n >> m >> s;

	for (int i = 0; i < m; ++i) {
		cin >> bugs[i].first;
		bugs[i].second = i;
	}

	sort(bugs, bugs + m, [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; });

	for (int i = 0; i < n; ++i) {
		cin >> students[i].ability;
		students[i].pos = i;
	}

	for (int i = 0; i < n; ++i) {
		cin >> students[i].pass;
	}

	sort(students, students + n, [](const st& a, const st& b) {
		if (a.ability != b.ability) {
			return a.ability > b.ability;
		}

		return a.pass < b.pass;
	});

	int lo = 1;
	int hi = m;
	bool found = false;


	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (can_do_within(mid)) {
			found = true;
			for (int i = 0; i < m; ++i) {
				res[i] = temp[i];
			}
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	if (not found) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES" << '\n';

	for (int i = 0; i < m; ++i) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

bool can_do_within(const int& days) {
	priority_queue<st, vector<st>, cmp> good_students;
	int curr_bug = 0;
	ll total_pass = 0;
	int curr_student = 0;

	while (curr_bug < m) {
		while (curr_student < n) {
			if (students[curr_student].ability < bugs[curr_bug].first) {
				break;
			}

			good_students.push(students[curr_student++]);
		}

		if (good_students.empty()) {
			return false;
		}

		st found_student = good_students.top();
		good_students.pop();

		for (int i = curr_bug; i < min(curr_bug + days, m); ++i) {
			temp[bugs[i].second] = found_student.pos + 1;
		}

		curr_bug += days;
		total_pass += found_student.pass;
	}

	return total_pass <= s;
}
