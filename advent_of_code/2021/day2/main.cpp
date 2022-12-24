#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x = 0, y = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; ll n;
	ll aim = 0;
	while (cin >> s >> n) {
		if (s == "forward")
			x += n,
			y += n*aim;
		else if (s == "down")
			aim += n;
		else if (s == "up")
			aim -= n;
		else
			throw s;
	}
	printf("%lld\n", x*y);
}
