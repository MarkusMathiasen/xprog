#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<list<string>> A(n, list<string>());
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		A[i].push_back(s);
	}
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		A[a].splice(A[a].end(), A[b]);
	}
	for (int i = 0; i < n; i++)
		if (A[i].begin() != A[i].end())
			for (string s : A[i])
				printf("%s", s.c_str());
	printf("\n");
}
