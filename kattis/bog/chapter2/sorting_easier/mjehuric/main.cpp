#include <bits/stdc++.h>
using namespace std;

int A[5];

void print() {
	for (int x : A)
		printf("%d ", x);
	printf("\n");
}

int main() {
	for (int i = 0; i < 5; i++)
		scanf("%d", A+i);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 4; j++)
			if (A[j] > A[j+1]) {
				int tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
				print();
			}
}
