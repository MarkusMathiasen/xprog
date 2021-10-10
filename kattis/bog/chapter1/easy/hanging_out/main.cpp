#include <bits/stdc++.h>
using namespace std;

int L, x, p = 0, res = 0;

int main() {
	scanf("%d %d", &L, &x);
	while (x--) {
		string s; int d;
		cin >> s >> d;
		if (s == "leave")
			p -= d;
		else {
			if (p+d <= L)
				p += d;
			else
				res++;
		}
	}
	printf("%d\n", res);
}
