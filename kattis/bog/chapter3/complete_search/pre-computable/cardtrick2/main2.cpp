#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		queue<int> Q;
		for (int i = n; i > 0; i--) {
			Q.push(i);
			for (int j = 0; j < i; j++)
				Q.push(Q.front()), Q.pop();
		}
		vector<int> res(n, 0);
		for (int i = 0; i < n; i++)
			res[i] = Q.front(),
				Q.pop();
		for (int i = n-1; i >= 0; i--)
			printf("%d ", res[i]);
		printf("\n");
	}
}
