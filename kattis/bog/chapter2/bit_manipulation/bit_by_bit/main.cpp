#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n, n) {
		vector<int> A(32, -1);
		for (int i = 0; i < n; i++) {
			string cmd; cin >> cmd;
			if (cmd == "CLEAR") {
				int i; cin >> i; A[i] = 0;
			} else if (cmd == "SET") {
				int i; cin >> i; A[i] = 1;
			} else if (cmd == "OR") {
				int i, j; cin >> i >> j;
				if (A[j] == 1)
					A[i] = 1;
				else if (A[j] == -1 && A[i] == 0)
					A[i] = -1;
			} else if (cmd == "AND") {
				int i, j; cin >> i >> j;
				if (A[j] == 0)
					A[i] = 0;
				else if (A[j] == -1 && A[i] == 1)
					A[i] = -1;
			} else
				throw cmd;
		}
		for (int i = 31; i >= 0; i--) {
			if (A[i] == -1)
				printf("?");
			else
				printf("%d", A[i]);
		}
		printf("\n");
	}
}
