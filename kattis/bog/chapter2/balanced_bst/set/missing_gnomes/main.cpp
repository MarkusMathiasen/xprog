#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<int> A(m, -1);
	set<int> gnomes;
	for (int i = 0; i < m; i++) {
		scanf("%d", &A[i]);
		gnomes.insert(A[i]);
	}
	int counter = 1;
	for (int i = 0; i < m; i++) {
		while (counter < A[i]) {
			if (!gnomes.count(counter))
				printf("%d\n", counter);
			counter++;
		}
		printf("%d\n", A[i]);
	}
	while (counter < n)
		printf("%d\n", ++counter);
}
