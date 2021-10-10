#include <bits/stdc++.h>
using namespace std;

int N, B, H, W;

int main() {
	scanf("%d%d%d%d", &N, &B, &H, &W);
	int res = 1e9;
	for (int i = 0; i < H; i++) {
		int p; scanf("%d", &p);
		int b = 0;
		for (int j = 0; j < W; j++) {
			int x; scanf("%d", &x);
			b = max(b, x);
		}
		if (b >= N)
			res = min(res, p*N);
	}
	if (res <= B)
		printf("%d\n", res);
	else
		printf("stay home\n");
}
