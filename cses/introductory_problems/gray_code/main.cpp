#include <bits/stdc++.h>

using namespace std;

int n;
int A = 0;

void print() {
	for (int i = n-1; i >= 0; i--)
		printf("%d", (A&(1 << i)) > 0);
	printf("\n");
}

void gray(int i) {
	if (i < 0) {
		print();
		return;
	}
	gray(i-1);
	A ^= (1 << i);
	gray(i-1);
}

int main() {
	cin >> n;
	gray(n-1);
}
