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
	string line1, line2, line3;
	int res = 0;
	while (cin >> line1 >> line2 >> line3) {
		set<char> s1, s2, s3;
		for (char c : line1)
			s1.insert(c);
		for (char c : line2)
			if (s1.count(c))
				s2.insert(c);
		for (char c : line3)
			if (s2.count(c))
				s3.insert(c);
		char common = *s3.begin();
		if (islower(common))
			res += common -'a'+1;
		else
			res += common-'A'+27;
	}
	printf("%d\n", res);
}
