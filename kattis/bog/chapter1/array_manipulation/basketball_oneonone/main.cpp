#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	char c;int d;
	bool aliceWon = false;
	while (scanf("%c%d", &c, &d) != EOF) {
		if (c == 'A')
			a += d;
		else
			b += d;
		if (a >= 11 && a > b+1) {
			aliceWon = true; break;
		}
		if (b >= 11 && b > a+1)
			break;
	}
	printf(aliceWon ? "A\n" : "B\n");
}
