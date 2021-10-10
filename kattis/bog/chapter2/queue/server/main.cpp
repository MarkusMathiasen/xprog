#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, T; scanf("%d%d", &n, &T);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		q.push(x);
	}
	int res = 0, cur = 0;
	while (q.size() && cur+q.front() <= T)
		cur += q.front(), q.pop(), res++;
	printf("%d\n", res);
}
