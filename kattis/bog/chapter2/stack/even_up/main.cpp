#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	stack<int> s;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		if (s.empty() || s.top()%2 != x%2)
			s.push(x);
		else
			s.pop();
	}
	printf("%d\n", (int)s.size());
}
