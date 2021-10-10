#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> s;
		for (int i = s.size()-2; i >= 0; i -= 2) {
			int x = (s[i] - '0')*2;
			s[i] = '0' + (x%10 + x/10);
		}
		int res = 0;
		for (char c : s)
			res += c-'0';
		printf(res%10 ? "FAIL\n" : "PASS\n");
	}
}
