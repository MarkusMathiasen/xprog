#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<char> s;
ll qs = 0;
ll z = 0;
ll o = 0;
ll q2 = 1;
ll res = 0;
ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char c;
	while (cin >> c) {
		s.push_back(c);
		if (c == '?')
			qs++;
		if (c == '0')
			z++;
		if (c == '1')
			o++;
	}
	ll zeros = 0;
	ll ones = 0;
	ll ques = 0;
	for (ll i = 0; i < qs; i++) {
		q2 *= 2;
		q2 %= 8*mod;
	}
	for (char c : s) {
		if (c == '0') {
			res += q2*ones;
			res %= mod;
			res += ques*q2/2;
			zeros++;
		}
		else if (c == '1') {
			ones++;
		}
		else if (c == '?') {
			res += ones*q2/2;
			res %= mod;
			res += ques*q2/4;
			ques++;
		}
		res %= mod;
	}
	cout << res << endl;
}
