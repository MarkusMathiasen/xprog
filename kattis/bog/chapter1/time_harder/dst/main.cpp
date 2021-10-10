#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	while (N--) {
		char c; int d, h, m; scanf(" %c%d%d%d", &c, &d, &h, &m);
		if (c == 'F')
			m += d;
		else if (c == 'B')
			m -= d;
		while (m > 59)
			m -= 60, h++;
		while (m < 0)
			m += 60, h--;
		while (h > 23)
			h -= 24;
		while (h < 0)
			h += 24;
		printf("%d %d\n", h, m);
	}
}
