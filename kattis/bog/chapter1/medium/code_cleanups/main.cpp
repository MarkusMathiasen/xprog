#include <bits/stdc++.h>
using namespace std;

int n, res = 0;
vector<int> days;
int dirt(int curr) {
	int res = 0;
	for (int d : days)
		res += curr-d;
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d; scanf("%d", &d);
		if (dirt(d) >= 20) {
			res++;
			days.assign(0, 0);
		}
		days.push_back(d);
	}
	printf("%d\n", res+1);
}
