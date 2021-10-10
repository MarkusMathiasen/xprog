#include <bits/stdc++.h>
using namespace std;

int s, v1, v2;

int main() {
	scanf("%d%d%d", &s, &v1, &v2);
	for (int i = 0; i <= s; i++) {
		int rest = s-i*v2;
		if (rest < 0)
			break;
		if (rest % v1 == 0) {
			printf("%d %d\n", rest / v1, i);
			return 0;
		}
	}
	printf("Impossible\n");
}
