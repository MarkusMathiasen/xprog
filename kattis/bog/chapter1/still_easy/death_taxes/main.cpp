#include <bits/stdc++.h>
using namespace std;

int s = 0;
double p = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string cmd;
	int x, y;
	while (cin >> cmd) {
		if (cmd == "buy") {
			cin >> x >> y;
			p = (s*p+x*y)/(s+x);
			s += x;
		}
		if (cmd == "sell") {
			cin >> x >> y;
			s -= x;
		}
		if (cmd == "split") {
			cin >> x;
			s *= x;
			p /= x;
		}
		if (cmd == "merge") {
			cin >> x;
			s /= x;
			p *= x;
		}
		if (cmd == "die") {
			cin >> y;
			break;
		}
	}
	double gain = y-p;
	printf("%f\n", gain > 0 ? s*(y - gain*0.3) : s*y);
}
