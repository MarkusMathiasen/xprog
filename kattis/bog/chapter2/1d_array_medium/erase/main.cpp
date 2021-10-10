#include <bits/stdc++.h>
using namespace std;

int n;
bool com(char a, char b) {
	return (n%2) == (int)(a != b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	string a, b; cin >> a >> b;
	bool res = true;
	for (int i = 0; i < (int)a.size(); i++)
		res &= com(a[i], b[i]);
	printf(res ? "Deletion succeeded\n" : "Deletion failed\n");
}
