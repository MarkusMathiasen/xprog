#include <bits/stdc++.h>
using namespace std;

int M, P, L, E, R, S, N;

void week() {
	int eggs = M * E;
	M = P / S;
	P = L / R;
	L = eggs;
}

int main() {
	while (scanf("%d%d%d%d%d%d%d", &M, &P, &L, &E, &R, &S, &N) != EOF) {
		while (N--)
			week();
		printf("%d\n", M);
	}
}
