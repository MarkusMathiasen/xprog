#include <bits/stdc++.h>
using namespace std;

int main() {
	int H; cin >> H; H++;
	string s; cin >> s;
	int pos = 0;
	for (char c : s)
		pos = pos*2 + (c == 'L');
	int n = 1;
	for (int i = 1; i < H; i++)
		n *= 2;
	int res = 0;
	for (int i = H; i > (int)s.size()+1; i--)
		res += n, n /= 2;
	res += pos+1;
	printf("%d\n", res);
}
