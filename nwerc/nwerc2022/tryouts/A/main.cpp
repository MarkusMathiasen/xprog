#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		ll N, M, a, b, d; scanf("%lld%lld%lld%lld%lld", &N, &M, &a, &b, &d);
		a--; b--;
		printf("%s\n", (a+(b-a)*2ll+d)%N >= N-M ? "NO" : "YES");
	}
}
