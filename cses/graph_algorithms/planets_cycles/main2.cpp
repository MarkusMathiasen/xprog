#include <bits/stdc++.h>

using namespace std;

int n;
int path[200000];
int vis[200000];
int track[200000];
int cdist[200000];

int calc(int i) {
	if (cdist[i]) return cdist[i];
	return cdist[i] = calc(path[i]) +1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &path[i]), path[i]--;
	for (int i = 0; i < n; i++)
		vis[i] = cdist[i] = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int nxt = i;
		int t = 1;
		vis[nxt] = i+1;
		track[nxt] = t; t++;
		while (!vis[path[nxt]]) {
			nxt = path[nxt];
			vis[nxt] = i+1;
			track[nxt] = t;
			t++;
		}
		if (vis[path[nxt]] != i+1) continue;
		t = track[nxt] - track[path[nxt]] +1;
		int g = nxt;
		cdist[g] = t;
		nxt = path[nxt];
		while (nxt != g) {
			cdist[nxt] = t;
			nxt = path[nxt];
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", calc(i));
	printf("\n");
}
