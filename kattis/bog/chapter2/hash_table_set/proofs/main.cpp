#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	string line; getline(cin, line);
	unordered_set<string> truth;
	for (int i = 1; i <= n; i++) {
		getline(cin, line);
		stringstream ss(line);
		string s;
		while (ss >> s) {
			if (s == "->")
				break;
			if (!truth.count(s)) {
				printf("%d\n", i);
				return 0;
			}
		}
		while (ss >> s)
			truth.insert(s);
	}
	printf("correct\n");
}
