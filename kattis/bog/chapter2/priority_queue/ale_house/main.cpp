#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main() {
	int n, k; scanf("%d%d", &n, &k);
	vector<ii> A(n, ii(0, 0));
	for (int i = 0; i < n; i++)
		scanf("%d%d", &A[i].first, &A[i].second);
	sort(A.begin(), A.end(), [](const ii& a, const ii& b){
		if (a.second != b.second)
			return a.second < b.second;
		return a.first < b.first;
	});
	int curr = 0, res = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (ii& x : A)
		pq.push(x.first);
	for (int i = 0; i < n; i++) {
		int start = A[i].second;
		while (!pq.empty() && pq.top() <= start+k)
			curr++, pq.pop();
		res = max(curr, res);
		curr--;
	}
	printf("%d\n", res);
}
