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
	int a, b, c, d;
	int res = 0;
	while (scanf("%d-%d,%d-%d", &a, &b, &c, &d) != EOF) {
		if (a <= c && b >= d || c <= a && d >= b)
			res++;
		else if (a <= c && b >= c || a <= d && b >= d)
			res++;
	}
	printf("%d\n", res);
}
