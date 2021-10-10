#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int res = 0;
vector<ii> seq;

void move(int num, int from, int to) {
	if (num == 1) {
		res++;
		seq.push_back(ii(from, to));
		return;
	}
	int other = 6 - from - to;
	move(num-1, from, other);
	move(1, from, to);
	move(num-1, other, to);
}

int main() {
	int n; cin >> n;
	move(n, 1, 3);
	printf("%d\n", res);
	for (ii p : seq)
		printf("%d %d\n", p.first, p.second);
}
