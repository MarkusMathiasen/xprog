#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
vector<string> huns = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
vector<string> order;

string gen(ll x) {
	string res = "";
	for (int i = 0; i < x/1000; i++)
		res += "M";
	x %= 1000;
	res += huns[x/100];
	x %= 100;
	res += tens[x/10];
	x %= 10;
	res += ones[x];
	return res;
}

ll pos(string x) {
	for (ll i = 0; i <= 1000; i++)
		if (order[i] == x)
			return i;
	throw x;
}

int main() {
	for (ll i = 0; i <= 1000; i++)
		order.push_back(gen(i));
	sort(order.begin(), order.end());
	int mpos = pos("M");
	scanf("%lld", &n);
	while (n--) {
		ll x; scanf("%lld", &x);
		ll m = x/1000;
		string s = gen(x%1000);
		ll p = pos(s);
		if (p <= mpos)
			printf("%lld\n", mpos*m+p);
		else
			printf("%lld\n", -54*m + p-order.size());
	}
}
