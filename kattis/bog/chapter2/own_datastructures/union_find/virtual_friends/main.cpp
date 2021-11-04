#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> p;
unordered_map<string, int> siz;

const string& find(const string& x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		p.clear(); siz.clear();
		int f; cin >> f;
		while (f--) {
			string a, b; cin >> a >> b;
			if (!p.count(a))
				p[a] = a, siz[a] = 1;
			if (!p.count(b))
				p[b] = b, siz[b] = 1;
			a = find(a);
			b = find(b);
			if (a != b) {
				p[a] = b;
				siz[b] += siz[a];
			}
			printf("%d\n", siz[b]);
		}
	}
}
