#include <bits/stdc++.h>
using namespace std;

void upd(int& x, char c) {
	if (c == 'b')
		x = 0;
	else
		x = max(x-1, 0);
}

int main() {
	int n; scanf("%d", &n);
	int lu = 8, ld = 8, ru = 8, rd = 8;
	while (n--) {
		char a, b, c; scanf(" %c%c %c", &a, &b, &c);
		if (isdigit(a) && b == '-')
			upd(rd, c);
		else if (isdigit(a) && b == '+')
			upd(ru, c);
		else if (isdigit(b) && a == '-')
			upd(ld, c);
		else if (isdigit(b) && a == '+')
			upd(lu, c);
		else
			assert(false);
	}
	if (lu && ld)
		printf("0\n");
	else if (ru && rd)
		printf("1\n");
	else
		printf("2\n");
}
