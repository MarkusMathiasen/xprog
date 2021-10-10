#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	stack<int> s1, s2;
	for (int i = 0; i < 2*n; i++) {
		int x; scanf("%d", &x);
		s1.push(x);
	}
	while (s1.size()) {
		if (!s2.size() || s2.top() != s1.top())
			s2.push(s1.top()), s1.pop();
		else
			s2.pop(), s1.pop();
	}
	if (s2.size())
		printf("impossible\n");
	else
		printf("%d\n", 2*n);
}
