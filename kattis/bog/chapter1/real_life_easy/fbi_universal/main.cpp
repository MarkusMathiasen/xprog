#include <bits/stdc++.h>
using namespace std;

int conv(char c, bool rec = false) {
	if ('0' <= c && c <= '9')
		return c-'0';
	if (c == 'A')
		return 10;

	if (c == 'B')
		return rec ? conv(c-1) : 8;
	if (c == 'G')
		return rec ? conv(c-1) : conv('C');
	if (c == 'I')
		return rec ? conv(c-1) : 1;
	if (c == 'O' || c == 'Q')
		return rec ? conv(c-1) : 0;
	if (c == 'S')
		return rec ? conv(c-1) : 5;
	if (c == 'U' || c == 'Y')
		return rec ? conv(c-1) : conv('V');
	if (c == 'Z')
		return rec ? conv(c-1) : 2;
	
	return conv(c-1, true)+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p; cin >> p;
	for (int test = 1; test <= p; test++) {
		printf("%d ", test);
		string s;
		cin >> test >> s;
		vector<long long> x;
		for (int i = 0; i < 8; i++)
			x.push_back(conv(s[i]));
		int check = conv(s.back());
		int realCheck = (2*x[0]+4*x[1]+5*x[2]+7*x[3]+8*x[4]+10*x[5]+11*x[6]+13*x[7])%27;
		if (check != realCheck)
			printf("Invalid\n");
		else {
			long long res = 0;
			long long mult = 1;
			for (int i = 0; i < 8; i++) {
				res += mult*x[7-i];
				mult *= 27;
			}
			printf("%lld\n", res);
		}

	}
}
