#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p, m; cin >> n >> p >> m;
	unordered_map<string, int> scores;
	string s;
	while (n--) {
		cin >> s;
		scores[s] = 0;
	}
	int x;
	bool found = false;
	while (m--) {
		cin >> s >> x;
		scores[s] += x;
		if (scores[s]-x < p && scores[s] >= p) {
			printf("%s wins!\n", s.c_str());
			found = true;
		}
	}
	if (!found)
		printf("No winner!\n");
}
