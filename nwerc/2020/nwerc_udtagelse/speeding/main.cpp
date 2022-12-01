#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;
	long long pret, pred; cin >> pret >> pred;
	n--;
	long long res = 0;
	while (n--) {
		long long t, d; cin >> t >> d;
		res = max(res, (d-pred)/(t-pret));
		pret = t;
		pred = d;
	}
	cout << res << endl;
}
