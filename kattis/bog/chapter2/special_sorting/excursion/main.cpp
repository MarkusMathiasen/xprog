#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll ones = 0;
	ll twos = 0;
	char c;
	ll res = 0;
	while (scanf("%c", &c) != EOF && c != '\n') {
		if (c == '0') {
			res += ones+twos;
		} else if (c == '1') {
			res += twos;
			ones++;
		} else if (c == '2') {
			twos++;
		} else
			throw c;
	}
	printf("%lld\n", res);
}
