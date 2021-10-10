#include <bits/stdc++.h>
using namespace std;

void pr(deque<int> d, bool rev) {
	printf("[");
	bool first = true;
	if (rev) {
		for (auto it = d.rbegin(); it != d.rend(); it++) {
			if (!first) {
				printf(",");
			}
			first = false;
			printf("%d", *it);
		}
	} else {
		for (auto it = d.begin(); it != d.end(); it++) {
			if (!first) {
				printf(",");
			}
			first = false;
			printf("%d", *it);
		}
	}
	printf("]\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string ops; cin >> ops;
		int n; cin >> n;
		deque<int> d;
		string l; cin >> l;
		l.erase(0, 1);
		l.pop_back();
		stringstream ss(l);
		string s;
		while (getline(ss, s, ','))
			d.push_back(stoi(s));
		bool rev = false;
		bool error = false;
		for (char c : ops) {
			if (c == 'R')
				rev = !rev;
			else if (c == 'D') {
				if (!d.size()) {
					error = true;
					break;
				}
				if (rev)
					d.pop_back();
				else
					d.pop_front();
			}
			else
				throw c;
		}
		if (error)
			printf("error\n");
		else
			pr(d, rev);
	}
}
