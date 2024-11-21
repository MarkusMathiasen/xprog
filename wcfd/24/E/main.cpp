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
	cin.exceptions(cin.failbit);
	ll x;
	cin >> x;
	printf("  ");
	rep(i, 0, x) printf("H ");
	printf("\n");
	printf("  ");
	rep(i, 0, x) printf("| ");
	printf("\n");

	printf("H-");
	rep(i, 0, x) printf("C-");
	printf("OH\n");

	printf("  ");
	rep(i, 0, x) printf("| ");
	printf("\n");
	printf("  ");
	rep(i, 0, x) printf("H ");
	printf("\n");
}
