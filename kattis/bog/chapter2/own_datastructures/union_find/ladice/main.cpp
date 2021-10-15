#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int> uf;

int find(int x) {
	if (x == -1)
		return -1;
	if (uf[x] == x)
		return x;
	return uf[x] = find(uf[x]);
}

int main() {
	scanf("%d%d", &n, &l);
	uf.assign(l, 0);
	for (int i = 0; i < l; i++)
		uf[i] = i;
	while (n--) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		int A = find(a), B = find(b);
		if (uf[a] == a) {
			printf("LADICA\n");
			if (B != A)
				uf[a] = B;
			else
				uf[a] = -1;
		}
		else if (uf[b] == b) {
			printf("LADICA\n");
			if (A != B)
				uf[b] = A;
			else
				uf[b] = -1;
		}
		else if (A != -1) {
			printf("LADICA\n");
			if (A != B)
				uf[A] = B;
			else
				uf[A] = -1;
		}
		else if (B != -1) {
			printf("LADICA\n");
			if (A != B)
				uf[B] = A;
			else
				uf[B] = -1;
		}
		else
			printf("SMECE\n");
	}
}
