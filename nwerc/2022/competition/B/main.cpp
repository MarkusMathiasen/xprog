#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int h, r, da, dw;

double center(double hg) {
	return (hg*hg*dw + h*h*da - hg*hg*da)/(hg*dw + h*da - hg*da);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	scanf("%d%d%d%d", &h, &r, &da, &dw);
	double low = 0, high = h, eps = 1e-8;
	while (low + eps < high && low * (1 + eps) < high) {
		double mid1 = (high-low)/3 + low;
		double mid2 = 2*(high-low)/3 + low;
		if (center(mid1) < center(mid2))
			high = mid2;
		else
			low = mid1;
	}
	printf("%lf\n", low);
}
