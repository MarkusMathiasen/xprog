#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	map<char, bool> m;
	for (int i = 0; i < n; i++) {
		char x; scanf(" %c", &x);
		m[i+'A'] = x == 'T';
	}
	char c;
	stack<bool> s;
	while (scanf(" %c", &c) != EOF) {
		if (isalpha(c))
			s.push(m[c]);
		else if (c == '*') {
			bool a = s.top(); s.pop();
			s.top() = s.top() && a;
		} else if (c == '+') {
			bool a = s.top(); s.pop();
			s.top() = s.top() || a;
		} else if (c == '-')
			s.top() = !s.top();
		else
			throw c;
	}
	printf(s.top() ? "T\n" : "F\n");
}
