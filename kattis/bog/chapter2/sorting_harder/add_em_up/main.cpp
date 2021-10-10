#include <bits/stdc++.h>
using namespace std;

vector<int> turned = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};
set<int> nums;
map<int, int> og;

bool turnable(int x) {
	bool res = true;
	while (x > 0)
		res &= turned[x%10] != -1, x /= 10;
	return res;
}

int turn(int x) {
	int res = 0;
	while (x > 0) {
		res *= 10;
		res += turned[x%10];
		x/= 10;
	}
	return res;
}

int main() {
	int n, s; scanf("%d%d", &n, &s);
	int id = 1;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		nums.insert(x);
		int nid = og[x] ? -1 : id;
		og[x] = nid;
		if (turnable(x)) {
			nums.insert(turn(x));
			og[turn(x)] = nid;
		}
		id++;
	}
	bool possible = false;
	for (int a : nums)
		possible |= nums.count(s-a) && (og[a] != og[s-a] || og[a] == -1);
	printf(possible ? "YES\n" : "NO\n");
}
