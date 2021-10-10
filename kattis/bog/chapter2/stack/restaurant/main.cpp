#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n, n) {
		stack<int> s1, s2;
		for (int i = 0; i < n; i++) {
			string cmd;int m; cin >> cmd >> m;
			if (cmd == "DROP") {
				printf("DROP 2 %d\n", m);
				s2.push(m);
			}
			else {
				assert(cmd == "TAKE");
				while (m) {
					if (s1.size()) {
						if (s1.top() > m) {
							printf("TAKE 1 %d\n", m);
							s1.top() -= m, m = 0;
						} else {
							printf("TAKE 1 %d\n", s1.top());
							m -= s1.top();
							s1.pop();
						}
					} else {
						while (s2.size()) {
							printf("MOVE 2->1 %d\n", s2.top());
							s1.push(s2.top()), s2.pop();
						}
					}
				}
			}
		}
		printf("\n");
	}
}
