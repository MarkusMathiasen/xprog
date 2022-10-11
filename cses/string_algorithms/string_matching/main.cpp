#include <bits/stdc++.h>
using namespace std;

vector<int> b;

void kmp_pre(string& sub) {
	b.assign(sub.size()+1, -1);
	int i = 0, j = -1;
	while (i < (int)sub.size()) {
		while (j >= 0 && sub[i] != sub[j])
			j = b[j];
		j++, i++;
		b[i] = j;
	}
}

int kmp_search(string& s, string& sub) {
	int i = 0, j = 0, res = 0;
	while (i < (int)s.size()) {
		while (j >= 0 && sub[j] != s[i])
			j = b[j];
		j++, i++;
		if (j == (int)sub.size())
			res++,
			j = b[j];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, sub; cin >> s >> sub;
	kmp_pre(sub);
	printf("%d\n", kmp_search(s, sub));
}
