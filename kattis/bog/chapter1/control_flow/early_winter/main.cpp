#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	int res = -1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x <= m) {
			res = i;
			break;
		}
	}
	if (res == -1)
		printf("It had never snowed this early!\n");
	else
		printf("It hadn't snowed this early in %d years!\n", res);
}
