#include <bits/stdc++.h>

using namespace std;

vector<int> uf;
int N, Q;

int find(int a) {
	if (uf[a] == a)
		return a;
	return uf[a] = find(uf[a]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		uf.push_back(i);
	while (Q--) {
		string s; int a, b; cin >> s >> a >> b;
		if (s == "?")
			printf(find(a) == find(b) ? "yes\n" : "no\n");
		else
			uf[find(a)] = find(b);
	}
}
