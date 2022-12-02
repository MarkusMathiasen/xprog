#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	char a, b, c;
	int res = 0;
	while (cin >> a >> c) {
		a += 'X'-'A';
		a -= 'X';
		c -= 'Y';
		b = (a+c+3)%3;
		res += b+1;
		if (a == b)
			res += 3;
		else if ((a+1)%3 == b)
			res += 6;
	}
	printf("%d\n", res);
}
