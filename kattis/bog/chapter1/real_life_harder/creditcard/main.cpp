#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;

int main() {
	scanf("%d", &T);
	while (T--) {
		ll r1, r2, b1, b2, m1, m2; scanf("%lld.%lld %lld.%lld %lld.%lld", &r1, &r2, &b1, &b2, &m1, &m2);
		ll R = r1*100+r2 + 10000;
		ll B = b1*100+b2;
		ll og = B;
		ll M = m1*100+m2;
		int i;
		for (i = 1; i <= 1200; i++) {
			B = B*R;
			if ((B%10000)/1000 >= 5)
				B += 10000;
			B /= 10000;
			B -= M;
			if (B <= 0)
				break;
			if (B > og)
				i = 1201;
		}
		if (i <= 1200)
			printf("%d\n", i);
		else
			printf("impossible\n");
	}
}
