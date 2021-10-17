#include <bits/stdc++.h>
using namespace std;

int arrow[1000001];

int main() {
	int n; scanf("%d", &n);
	memset(arrow, false, sizeof arrow);
	int res = 0;
	while (n--) {
		int x; scanf("%d", &x);
		if (arrow[x])
			arrow[x]--, arrow[x-1]++;
		else
			arrow[x-1]++, res++;
	}
	printf("%d\n", res);
}
