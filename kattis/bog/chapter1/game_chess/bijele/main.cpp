#include <bits/stdc++.h>
using namespace std;

int x;

void f(int n) {
	scanf("%d", &x);
	printf("%d ", n-x);
}

int main() {
	for (int i = 0; i < 2; i++)
		f(1);
	for (int i = 0; i < 3; i++)
		f(2);
	f(8);
	printf("\n");
}
