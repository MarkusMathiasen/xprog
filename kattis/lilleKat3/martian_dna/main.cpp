#include <bits/stdc++.h>

using namespace std;

int N, K, R;
vector<int> A;
vector<int> req;
int satNum = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K >> R;
	A.assign(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	req.assign(K, 0);
	for (int i = 0; i < R; i++) {
		int b, q; cin >> b >> q;
		req[b] = q;
	}
	int res = 1e9;
	for (int r : req)
		if (r == 0)
			satNum++;
	int start = 0;
	int end = -1;
	if (satNum == N)
		res = 0;
	vector<int> count(K, 0);
	while (true) {
		if (satNum == K) {
			res = min(res, end-start+1);
			count[A[start]]--;
			if (count[A[start]]+1 == req[A[start]])
				satNum--;
			start++;
			continue;
		}
		if (end == N-1)
			break;
		end++;
		count[A[end]]++;
		if (count[A[end]] == req[A[end]])
			satNum++;
	}
	if (res == 1e9)
		printf("impossible\n");
	else
		printf("%d\n", res);
}
