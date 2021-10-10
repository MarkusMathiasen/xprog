#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	for (int j = 0; j < n; j++) {
		int g; cin >> g;
		int A[g];
		for (int i = 0; i < g; i++)
			cin >> A[i];
		int kpos = 0;
		for (int i = 1; i < g; i++)
			if (A[i] != A[i-1]+1) {
				kpos = i+1;
				break;
			}
		cout << kpos << endl;
	}
}
