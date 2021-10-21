#include <bits/stdc++.h>
using namespace std;
#define ll long long

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		ost A;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			ll x; scanf("%lld", &x);
			A.insert(x);
			if (i%2 == 0)
				sum += *A.find_by_order(i/2);
			else {
				ll a = *A.find_by_order(i/2);
				ll b = *A.find_by_order(i/2+1);
				sum += (a+b)/2;
			}
		}
		printf("%lld\n", sum);
	}
}
