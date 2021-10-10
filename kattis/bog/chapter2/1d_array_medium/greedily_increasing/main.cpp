#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> res = {0};
	while (n--) {
		int x; scanf("%d", &x);
		if (x > res.back())
			res.push_back(x);
	}
	printf("%d\n", (int)res.size()-1);
	for (int i = 1; i < (int)res.size(); i++)
		printf("%d ", res[i]);
	printf("\n");
}
