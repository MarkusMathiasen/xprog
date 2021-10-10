#include <bits/stdc++.h>
using namespace std;

vector<int> digits;

void countDigits(int x) {
	while (x) {
		digits[x%10]++;
		x /= 10;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s; getline(cin, s);
		getline(cin, s);
		cout << s << "\n";
		int addr; cin >> addr >> s;
		cout << addr << " " << s << "\n";
		digits.assign(10, 0);
		while (addr) {
			cin >> s;
			if (s == "+") {
				int a, b, c; cin >> a >> b >> c;
				for (int i = a; i <= b; i += c) {
					addr--;
					countDigits(i);
				}
			}
			else {
				countDigits(stoi(s));
				addr--;
			}
		}
		for (int i = 0; i < 10; i++)
			cout << "Make " << digits[i] << " digit " << i << "\n";
		int sum = 0;
		for (int x : digits)
			sum += x;
		cout << "In total " << sum << (sum == 1 ? " digit\n" : " digits\n");
	}
}
