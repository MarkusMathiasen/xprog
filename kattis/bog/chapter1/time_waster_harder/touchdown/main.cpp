#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	int lastpos = 20;
	int pos = 20;
	int tries = 4;
	while (N-- && tries--) {
		int x; scanf("%d", &x);
		pos += x;
		if (pos <= 0 || pos >= 100)
			break;
		if (pos-10 >= lastpos)
			tries = 4, lastpos = pos;
	}
	if (pos >= 100)
		printf("Touchdown\n");
	else if (pos <= 0)
		printf("Safety\n");
	else
		printf("Nothing\n");
}
