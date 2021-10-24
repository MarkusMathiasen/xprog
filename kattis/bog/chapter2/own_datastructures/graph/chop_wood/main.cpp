#include <bits/stdc++.h>
using namespace std;

int n, A[200001] = {0}, v[200001] = {0};

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		A[i]++;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x); x--;
		A[x]++;
		v[i] = x;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n+1; i++)
		if (A[i] == 1)
			pq.push(i);
	vector<int> res;
	bool possible = true;
	for (int i = 0; i < n; i++) {
		if (pq.size() < 2) {
			possible = false;
			break;
		}
		int x = pq.top(); pq.pop();
		res.push_back(x+1);
		A[v[i]]--;
		if (A[v[i]] == 1)
			pq.push(v[i]);
	}
	if (!possible)
		printf("Error\n");
	else
		for (int x : res)
			printf("%d\n", x);
}
