#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
vector<ll> A;

int main() {
	cin >> n;
	A.assign(n, 0);
	for (ll i = 0; i < n; i++)
		cin >> A[i];

	bool found = false;
	for (ll i = 0; i < n-1 && !found; i++) {
		if (A[i] == 0) {
			if (9 > A[i+1]) {
				A[i] = 9;
				found = true;
			}
		}
		for (ll j = 1; j <= A[i] && !found; j *= 10) {
			ll left = A[i]/j - ((A[i]/j) % 10);
			ll k = (left + 9)*j + A[i] % j;
			if (k > A[i+1]) {
				A[i] = k;
				found = true;
			}
		}
	}

	for (ll i = 1; i < n && !found; i--) {
		for (ll j = 1; j <= A[i] && !found; j *= 10) {
			ll left = A[i]/j - ((A[i]/j) % 10);
			ll k = (left + 0)*j + A[i] % j;
			if (j * 10 > A[i] && A[i] > 9)
				k = (left + 1)*j + A[i] % j;
			if (k < A[i-1]) {
				A[i] = k;
				found = true;
			}
		}
	}
	if (!found) {
		cout << "impossible" << endl;
		return 0;
	}
	for (ll i = 0; i < n-1; i++)
		cout << A[i] << " ";
	cout << A[n-1] << endl;
}
