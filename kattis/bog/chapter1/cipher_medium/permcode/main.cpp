#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	string S, P, C;
	while (cin >> x, x) {
		cin >> S >> P >> C;
		int n = C.size();
		int d = (int)(n*sqrt(n)+x)%n;
		string M = "";
		for (int i = 0; i < n; i++)
			M.push_back(' ');
		M[d] = P[S.find(C[d])];
		for (int i = (d == 0 ? n-1 : d-1); i != d; i = (i == 0 ? n-1 : i-1)) {
			int nxt = i == n-1 ? 0 : i+1;
			int x1 = S.find(M[nxt]);
			int x2 = S.find(C[i]) ^ x1;
			M[i] = P[x2];
		}
		cout << M << endl;
	}
}
