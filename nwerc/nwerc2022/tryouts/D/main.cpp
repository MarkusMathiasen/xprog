#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n; scanf("%lld", &n);
	ll sum = 0, x;
	for (int i = 0; i < n; i++)
		scanf("%lld", &x),
		sum += x;
	printf("%s\n", sum%3 ? "no" : "yes");
}
