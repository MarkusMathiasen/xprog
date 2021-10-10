#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int calc(int a, int b) {
	int high = max(a, b);
	int low = min(a, b);
	if (high == 2 && low == 1)
		return 1000;
	if (high == low)
		return (high*10+low)*10;
	else
		return (high*10+low);
}

int main() {
	while (cin >> a >> b >> c >> d) {
		if (a == 0)
			break;
		if (calc(a, b) > calc(c, d))
			printf("Player 1 wins.\n");
		else if (calc(a, b) < calc(c, d))
			printf("Player 2 wins.\n");
		else
			printf("Tie.\n");
	}
}
