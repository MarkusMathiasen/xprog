#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, s; scanf("%d%d", &m, &s);
	int A[m][s];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < s; j++)
			scanf("%d", &A[i][j]);
	set<int> res;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < m; j++)
			res.insert(A[j][i]);
		if ((int)res.size() == i+1)
			break;
	}
	printf("%d\n", (int)res.size());
	for (int x : res)
		printf("%d ", x);
	printf("\n");
}
