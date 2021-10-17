#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n, n) {
		vector<string> A(n, "");
		for (int i = 0; i < n; i++)
			cin >> A[i];
		stable_sort(A.begin(), A.end(), [](string const& a, string const& b) {
			return a.substr(0, 2) < b.substr(0, 2);
		});
		for (string s : A)
			cout << s << "\n";
		cout << "\n";
	}
}
