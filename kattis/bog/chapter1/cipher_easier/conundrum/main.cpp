#include <bits/stdc++.h>
using namespace std;

string s;
string per = "PER";
int res = 0;

int main() {
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] != per[i%3])
			res++;
	cout << res << endl;
}
