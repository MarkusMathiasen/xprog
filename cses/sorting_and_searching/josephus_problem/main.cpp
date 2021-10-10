#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nxt;

int main() {
	cin >> n;
	nxt.assign(n+1, 0);
	for (int i = 1; i < n; i++)
		nxt[i] = i+1;
	nxt[n] = 1;
	int pos = 1;
	for (int i = 0; i < n; i++) {
		printf("%d ", nxt[pos]);
		nxt[pos] = nxt[nxt[pos]];
		pos = nxt[pos];
	}
	printf("\n");
}
