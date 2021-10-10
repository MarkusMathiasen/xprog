#include <bits/stdc++.h>

using namespace std;

int n, k;
set<char> s;
string word;

int main() {
	scanf("%d %d\n", &n, &k);
	cin >> word;
	while (k--) {
		char c; cin >> c;
		s.insert(c);
	}
	long long res = 0;
	int curr = 0;
	for (int i = 0; i < (int)word.size(); i++) {
		if (s.count(word[i])) {
			curr++;
			res += curr;
		}
		else {
			curr = 0;
		}
	}
	cout << res << endl;
}
