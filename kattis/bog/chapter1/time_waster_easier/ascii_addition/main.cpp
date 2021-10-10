#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<string>> v = {
	{"xxxxx",
	"x...x",
	"x...x",
	"x...x",
	"x...x",
	"x...x",
	"xxxxx"},

	{"....x",
	"....x",
	"....x",
	"....x",
	"....x",
	"....x",
	"....x"},
	
	{"xxxxx",
	"....x",
	"....x",
	"xxxxx",
	"x....",
	"x....",
	"xxxxx"},

	{"xxxxx",
	"....x",
	"....x",
	"xxxxx",
	"....x",
	"....x",
	"xxxxx"},
	
	{"x...x",
	"x...x",
	"x...x",
	"xxxxx",
	"....x",
	"....x",
	"....x"},

	{"xxxxx",
	"x....",
	"x....",
	"xxxxx",
	"....x",
	"....x",
	"xxxxx"},

	{"xxxxx",
	"x....",
	"x....",
	"xxxxx",
	"x...x",
	"x...x",
	"xxxxx"},

	{"xxxxx",
	"....x",
	"....x",
	"....x",
	"....x",
	"....x",
	"....x"},

	{"xxxxx",
	"x...x",
	"x...x",
	"xxxxx",
	"x...x",
	"x...x",
	"xxxxx"},

	{"xxxxx",
	"x...x",
	"x...x",
	"xxxxx",
	"....x",
	"....x",
	"xxxxx"},

	{".....",
	"..x..",
	"..x..",
	"xxxxx",
	"..x..",
	"..x..",
	"....."}
};
vector<string> inp(7, "");

ll toNum(ll pos) {
	pos *= 6;
	vector<string> in;
	for (ll i = 0; i < 7; i++)
		in.push_back(inp[i].substr(pos, 5));
	for (ll i = 0; i <= 10; i++)
		if (in == v[i])
			return i;
	throw pos;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (ll i = 0; i < 7; i++)
		cin >> inp[i];
	ll a = 0, b = 0;
	bool p = false;
	for (ll i = 0; i <= (ll)inp[0].size()/6; i++) {
		if (toNum(i) == 10)
			p = true;
		else {
			if (p)
				b *= 10, b += toNum(i);
			else
				a *= 10, a += toNum(i);
		}
	}
	ll res = a+b;
	ll lres = to_string(res).size();
	ll x = 1;
	for (ll i = 1; i < lres; i++)
		x *= 10;
	ll y = x;
	for (ll j = 0; j < 7; j++) {
		for (ll i = 0; i < (ll)to_string(res).size(); i++) {
			if (i > 0)
				printf(".");
			printf("%s", v[(res%(10*x))/x][j].c_str());
			x /= 10;
		}
		printf("\n");
		x = y;
	}
}
