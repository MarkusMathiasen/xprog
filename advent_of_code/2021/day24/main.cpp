#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct op {
	string o;
	char v;
	char v2 = 'a';
	int val;

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<op> ops;
	string s;
	while (getline(cin, s), s != "") {
		stringstream ss(s);
		op x; ss >> x.o >> x.v >> s;
		if (isdigit(s.back()))
			x.val = stoi(s);
		else
			x.v2 = s[0];
		ops.push_back(x);
	}
	ll mn;
	for (mn = 99999999999999; mn > 0; mn--) {
		string num = to_string(mn);
		int npos = 0;
		map<char,int> m;
		m['x'] = m['y'] = m['z'] = m['w'] = 0;
		for (op& x : ops) {
				if (x.o == "inp")
					m[x.v] = num[npos++]-'0';
				else if (x.o == "add")
					m[x.v] += x.v2 == 'a' ? x.val : m[x.v2];
				else if (x.o == "mul")
					m[x.v] *= x.v2 == 'a' ? x.val : m[x.v2];
				else if (x.o == "div")
					m[x.v] /= x.v2 == 'a' ? x.val : m[x.v2];
				else if (x.o == "mod")
					m[x.v] %= x.v2 == 'a' ? x.val : m[x.v2];
				else if (x.o == "eql")
					m[x.v] = m[x.v] == (x.v2 == 'a' ? x.val : m[x.v2]);
				else throw x;
			}
		if (m['z'] == 0)
			break;
	}
	printf("%lld\n", mn);
}
