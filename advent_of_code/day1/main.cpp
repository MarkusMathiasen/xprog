#include <bits/stdc++.h>
using namespace std;

int main() {
	int prev = scanf("%d", &prev);
	int x;
	int res = 0;
	while (scanf("%d", &x) != EOF)
		res += x > prev,
		prev = x;
	printf("%d\n", res);
}		
