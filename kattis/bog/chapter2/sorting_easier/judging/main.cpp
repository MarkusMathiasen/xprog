#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_map<string, int> dom, kattis;
	unordered_set<string> grades;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		dom[s]++;
		grades.insert(s);
	}
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		kattis[s]++;
	}
	int res = 0;
	for (string s : grades)
		res += min(dom[s], kattis[s]);
	printf("%d\n", res);
}
