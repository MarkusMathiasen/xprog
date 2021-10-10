#include <bits/stdc++.h>
using namespace std;

int m, l, M, L, mt, tl, TM, TL;

int main() {
	scanf("%d%d%d%d%d%d", &m, &l, &M, &L, &mt, &tl);
	TM = abs(m) + abs(m - M);
	TL = abs(M-l) + abs(l-L) + TM;
	if (TM <= mt && TL <= tl) {
		printf("possible\n");
		return 0;
	}
	TL = abs(l) + abs(l - L);
	TM = abs(L - m) + abs(m - M) + TL;
	if (TM <= mt && TL <= tl) {
		printf("possible\n");
		return 0;
	}
	TM = abs(m) + abs(m-l) + 2*abs(l-L) + abs(l-M);
	TL = abs(m) + abs(m-l) + abs(l-L);
	if (TM <= mt && TL <= tl) {
		printf("possible\n");
		return 0;
	}
	TL = abs(l) + abs(l-m) + 2*abs(m-M)+ abs(m-L);
	TM = abs(l) + abs(l-m) + abs(m-M);
	if (TM <= mt && TL <= tl) {
		printf("possible\n");
		return 0;
	}
	printf("impossible\n");
}
