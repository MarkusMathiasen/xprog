#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<bool> b(n, false);
		vector<int> A(n, 0);
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 1; i < n; i++) {
			int val = abs(A[i]-A[i-1]);
			if (val > n-1 || val < 0)
				break;
			b[val] = true;
		}
		bool res = true;
		for (int i = 1; i < n; i++)
			res &= b[i];
		printf(res ? "Jolly\n" : "Not jolly\n");
	}
}
