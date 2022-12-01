#include <bits/stdc++.h>
using namespace std;

string ask(int a, int b) {
	cout << "? " << a << " " << b << endl;
	string ans; cin >> ans;
	return ans;
}
void result(int x) {
	cout << "! " << x << endl;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n-2; i+=2) {
		string ans = ask(i, i+1);
		if (ans != "equal") {
			ans = ask(i, n);
			if (ans != "equal")
				result(i);
			else
				result(i+1);
			return 0;
		}
	}
	if (n%2 == 1) {
		result(n);
		return 0;
	}
	string ans = ask(1, n);
	if (ans == "equal")
		result(n-1);
	else
		result(n);
}
