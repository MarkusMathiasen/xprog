#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t = 1;
	while (cin >> n, n) {
		printf("SET %d\n", t++);
		vector<string> A(n, "");
		for (int i = 0; i < n; i++)
			if (i%2 == 0)
				cin >> A[i/2];
			else
				cin >> A[n-1-i/2];
		for (string& s : A)
			printf("%s\n", s.c_str());
	}
}
