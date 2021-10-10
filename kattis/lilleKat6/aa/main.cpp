#include <bits/stdc++.h>
using namespace std;

bool comp(string& a, string& b) {
	for (int i = 0; i < (int)min(a.size(), b.size()); i++) {
		if (i < (int)b.size()-1 && b[i] == 'a' && b[i+1] == 'a')
			return true;
		if (a[i] < b[i])
			return true;
		if (a[i] > b[i])
			return false;
	}
	return a.size() <= b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	string prev = "";
	string nxt = "";
	bool res = true;
	while (n--) {
		prev = nxt; cin >> nxt;
		res &= comp(prev, nxt);
	}
	printf(res ? "yes\n" : "no\n");
}
