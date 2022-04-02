#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string bin = "";
ll toInt(ll pos, ll len) {
	ll v = 0;
	for (ll i = 0; i < len; i++)
		if (bin[pos+i] == '1')
			v |= (1<<(len-1-i));
	return v;
}

ll packet(ll& pos) {
	assert(pos < (ll)bin.size());
	ll v = toInt(pos, 3);
	pos += 3;
	ll t = toInt(pos, 3);
	pos += 3;
	if (t == 4) {
		bool done = false;
		string num = "";
		while (!done) {
			done = bin[pos] == '0';
			for (ll i = 1; i < 5; i++)
				num.push_back(bin[pos+i]);
			pos += 5;
		}
		ll res = 0;
		ll n = num.size();
		assert(n < 64);
		for (ll i = 0; i < n; i++)
			if (num[i] == '1')
				res |= (1<<(n-1-i));
		return res;
	}
	else if (t != 4) {
		function<ll(ll, ll)> op;
		switch (t) {
			case 0: op = [](const ll a, const ll b){assert(a+b > a && a+b > b); return a+b;}; break;
			case 1: op = [](const ll a, const ll b){assert(a*b > a && a*b > b); return a*b;}; break;
			case 2: op = [](const ll a, const ll b){return min(a,b);}; break;
			case 3: op = [](const ll a, const ll b){return max(a,b);}; break;
			case 5: op = [](const ll a, const ll b){return a > b;}; break;
			case 6: op = [](const ll a, const ll b){return a < b;}; break;
			case 7: op = [](const ll a, const ll b){return a == b;}; break;
			default: throw t;
		}
		ll lt = bin[pos];
		pos++;
		ll res;
		if (lt == '1') {
			ll packNum = toInt(pos, 11);
			pos += 11;
			res = packet(pos);
			for (ll i = 1; i < packNum; i++)
				res = op(res, packet(pos));
		}
		else {
			ll len = toInt(pos, 15);
			pos += 15;
			ll end = pos+len;
			res = packet(pos);
			while (pos < end)
				res = op(res, packet(pos));
		}
		return res;
	}
	else throw v;
}

int main() {
	string s; cin >> s;
	for (char c : s) {
		ll x = isdigit(c) ? c-'0' : c-'A'+10;
		for (ll i = 3; i >= 0; i--)
			bin.push_back((!(!(x&(1<<i)))) + '0');
	}
	ll x = 0;
	ll v = packet(x);
	printf("%lld\n", v);
}
