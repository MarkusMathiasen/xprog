#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	string a, b; cin >> a >> b;
	int r = 0, s = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == b[i]) {
			r++;
			a[i] = 'x';
			b[i] = 'y';
		}
	for (int i = 0; i < n; i++) {
		if (b.find(a[i]) != string::npos) {
			int pos = b.find(a[i]);
			s++;
			a[i] = 'x';
			b[pos] = 'y';
		}
	}
	printf("%d %d\n", r, s);

}
