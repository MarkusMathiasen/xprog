#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;
	if (n % 2 == 0)
		cout << (n/2+1)*(n/2+1) << endl;
	else {
		int c = (n+1)/2;
		cout << c*(c+1)*2 << endl;
	}
}
