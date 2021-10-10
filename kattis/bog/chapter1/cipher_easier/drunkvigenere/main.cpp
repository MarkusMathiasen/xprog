#include <bits/stdc++.h>
using namespace std;

string s, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> k;
	for (int i = 0; i < (int) s.size(); i++) {
		if (i%2 == 0)
			s[i] = (s[i]-'A' + 26-(k[i]-'A'))%26 + 'A';
		else
			s[i] = (s[i]-'A' + k[i]-'A')%26 + 'A';
	}
	cout << s << endl;
}
