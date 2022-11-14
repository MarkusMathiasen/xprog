#include <bits/stdc++.h>
using namespace std;

int low_var = 3;
int high_var = 5;

void print_fizz(int x) {
	if (x%low_var == 0)
		printf("Gin");
	if (x%high_var == 0)
		printf("Fizz");
	if (x%low_var != 0 && x%high_var != 0)
		printf("%d", x);
	printf("\n");
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		print_fizz(i);
}
