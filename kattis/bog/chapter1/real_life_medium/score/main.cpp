#include <bits/stdc++.h>
using namespace std;

int n, score = 0, H = 0, A = 0, last = 0;

int main() {
	scanf("%d", &n);
	while (n--) {
		char c; int p, m, s; scanf(" %c%d%d:%d", &c, &p, &m, &s);
		int t = m*60+s;
		if (score > 0)
			H += t - last;
		else if (score < 0)
			A += t - last;
		last = t;
		if (c == 'H')
			score += p;
		else
			score -= p;
	}
	if (score > 0)
		H += 32*60 - last;
	else if (score < 0)
		A += 32*60 - last;
	printf("%c %d:%02d %d:%02d\n", score > 0 ? 'H' : 'A', H/60, H%60, A/60, A%60);
}
