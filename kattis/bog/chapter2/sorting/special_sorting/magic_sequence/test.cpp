#include <bits/stdc++.h>
using namespace std;

int A[] = {0, 1, 2};

void func(int B[]) {
	B[0] = 100;
}

int main() {
	func(A);
	printf("%d\n", A[0]);
}
