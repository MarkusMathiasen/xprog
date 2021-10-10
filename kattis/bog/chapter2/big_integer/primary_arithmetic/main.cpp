#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll a, b;
	while (scanf("%lld%lld", &a, &b), a || b) {
		int res = 0;
		int carry = 0;
		while (a || b) {
			int x = a%10; a /= 10;
			int y = b%10; b /= 10;
			if (x+y+carry >= 10) {
				res++;
				carry = 1;
			}
			else
				carry = 0;
		}
		if (!res)
			printf("No carry operation.\n");
		else if (res == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", res);
	}
}
