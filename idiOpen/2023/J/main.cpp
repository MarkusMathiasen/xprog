#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int W, H, D;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	scanf("%d%d%d", &W, &H, &D);
	pair<int, int> J, camp;
	rep(i, 0, H) rep(j, 0, W) {
		char c; scanf(" %c", &c);
		if (c == 'J') J = {i, j};
		if (c == '@') camp = {i, j};
	}
	if ((J.first - camp.first)*(J.first - camp.first)
		+ (J.second - camp.second)*(J.second - camp.second) <= D*D)
		printf("the guide is right\n");
	else
		printf("no jumpscares here\n");
}
