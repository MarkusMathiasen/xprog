#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (c); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	int x = 1;
	int cycle = 0;
	string s; int k;
	int res = 0;
	vector<string> A;
	while (cin >> s) {
		if ((cycle) % 40 == 0) {
			res += x*cycle;
			A.push_back("");
		}
		A.back().push_back(abs(cycle%40-x) <= 1 ? '#' : '.');
		if (s == "addx") {
			cin >> k;
			cycle++;
			if (cycle % 40 == 0) {
				res += x*cycle;
				A.push_back("");
			}
			A.back().push_back(abs(cycle%40-x) <= 1 ? '#' : '.');
			x += k;
			cycle++;
		} else if (s == "noop") {
			cycle++;
		}
	}
	if ((x-20) % 40 == 0) {
		res += k*cycle;
		A.push_back("");
	}
	for (string& s : A)
		printf("%s\n", s.c_str());
}
