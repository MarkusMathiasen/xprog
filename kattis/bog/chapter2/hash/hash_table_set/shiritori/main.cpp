#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_set<string> s;
	string prev; cin >> prev;
	s.insert(prev);
	for (int i = 1; i < n; i++) {
		string w; cin >> w;
		if (s.count(w) || w[0] != prev.back()) {
			printf("Player %d lost\n", (i%2)+1);
			return 0;
		}
		prev = w;
		s.insert(prev);
	}
	printf("Fair Game\n");
}
