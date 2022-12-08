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
	vector<string> A;
	string line;
	while (cin >> line)
		A.push_back(line);
	vector<vector<int>> vis(sz(A), vector<int>(sz(A[0]), 1));
	int res = 0;
	rep(i, 1, sz(A)-1)
		rep(j, 1, sz(A[i])-1) {
			int v = 1;
			int j2 = j-1;
			while (j2 > 0 && A[i][j] > A[i][j2])
				j2--;
			v *= j-j2;
			j2 = j+1;
			while (j2+1<sz(A[i]) && A[i][j] > A[i][j2])
				j2++;
			v *= j2-j;
			int i2 = i-1;
			while (i2 > 0 && A[i][j] > A[i2][j])
				i2--;
			v *= i-i2;
			i2 = i+1;
			while (i2+1<sz(A) && A[i][j] > A[i2][j])
				i2++;
			v *= i2-i;
			res = max(res, v);
		}
	printf("%d\n", res);
}
