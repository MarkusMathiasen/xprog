#include <bits/stdc++.h>
using namespace std;

struct que {
	int val;
	int nxt;
	que(int val, int nxt) : val(val), nxt(nxt) {}
	bool operator < (const que& a) const {
		return nxt < a.nxt;
	}
};

int main() {
	int c, n, a; scanf("%d%d%d", &c, &n, &a);
	vector<int> A(a, -1);
	for (int i = 0; i < a; i++)
		scanf("%d", &A[i]);
	vector<int> nxt(a, 1000000);
	map<int, int> seen;
	for (int i = a-1; i >= 0; i--) {
		if (seen.count(A[i]))
			nxt[i] = seen[A[i]];
		seen[A[i]] = i;
	}
	int res = 0;
	set<que> q;
	set<int> cache;
	for (int i = 0; i < a; i++) {
		if (cache.count(A[i])) { // Already in cache
			auto it = q.lower_bound(que(A[i], i));
			q.erase(it);
			q.insert(que(A[i], nxt[i]));
		}
		else { // Not in cache
			res++;
			if ((int)q.size() == c) {
				auto it = --q.end();
				cache.erase(cache.find(it->val));
				q.erase(it);
			}
			q.insert(que(A[i], nxt[i]));
			cache.insert(A[i]);
		}
	}
	printf("%d\n", res);
}
