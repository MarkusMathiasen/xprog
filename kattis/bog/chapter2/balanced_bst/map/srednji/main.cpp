#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, b; scanf("%d%d", &n, &b);
	vector<int> left;
	unordered_map<int, ll> right;
	int bpos;
	vector<int> A(n, -1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		if (A[i] == b)
			bpos = i;
	}
	int count = 0;
	for (int i = bpos; i >= 0; i--) {
		if (A[i] > b)
			count++;
		if (A[i] < b)
			count--;
		left.push_back(count);
	}
	count = 0;
	for (int i = bpos; i < n; i++) {
		if (A[i] > b)
			count++;
		else if (A[i] < b)
			count--;
		right[count]++;
	}
	ll res = 0;
	for (int x : left)
		res += right[-x];
	printf("%lld\n", res);
}
