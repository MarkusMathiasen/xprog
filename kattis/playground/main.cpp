#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N;
	while (scanf("%d", &N), N) {
		vector<ll> A(N, 0);
		for (int i = 0; i < N; i++) {
			ll a, b; scanf("%lld.%lld", &a, &b);
			A[i] = a*1000ll + b;
		}
		sort(A.begin(), A.end());
		vector<int> presum(N+1, 0);
		for (int i = 1; i <= N; i++)
			presum[i] = presum[i-1]+A[i-1];
		bool res = false;
		for (int i = 0; i < N; i++)
			res |= A[i] <= presum[i];
		printf("%s\n", res ? "YES" : "NO");
	}
}
