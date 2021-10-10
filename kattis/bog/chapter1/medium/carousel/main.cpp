#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	while (scanf("%d%d", &n, &m)) {
		if (n == 0)
			break;
		int a = -1, b = 0;
		for (int i = 0; i < n; i++) {
			int na, nb; scanf("%d%d", &na, &nb);
			if (na > m)
				continue;
			if (a == -1)
				a = na, b = nb;
			else if (na * b > a * nb)
				a = na, b = nb;
			else if (na * b == a * nb && na > a)
				a = na, b = nb;
		}
		if (a == -1)
			printf("No suitable tickets offered\n");
		else
			printf("Buy %d tickets for $%d\n", a, b);
	}
}
