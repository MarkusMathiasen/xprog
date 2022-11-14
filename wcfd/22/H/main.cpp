#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string prev; cin >> prev;
	n--;
	int res = 0;
	while (n--) {
		string cur; cin >> cur;
		if (prev == "drunk" && cur == "sober")
			res++;
		prev = cur;
	}
	printf("%d\n", res);
}
