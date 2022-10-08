#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	vector<ll> A(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	vector<ll> minis, maxis;
	int i = 1;
	for (i = 1; i < n; i++) {
		if (A[i] > A[i-1]) {
			minis.push_back(A[i-1]); 
			break;
		}
	}
	for (; i < n; i++) {
		if (A[i] < A[i-1] && maxis.size() < minis.size()) {
			maxis.push_back(A[i-1]);
		 } else if (A[i] > A[i-1] && maxis.size() == minis.size()) {
			minis.push_back(A[i-1]);
		 }
	}
	if (maxis.size() == minis.size())
		minis.push_back(A[n-1]);
	ll res = 0;
	for (int i = 0; i < maxis.size(); i++) {
		res = max(res, min(maxis[i]-minis[i], maxis[i]-minis[i+1]));
	}
	printf("%lld\n", res);
}
