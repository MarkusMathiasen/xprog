#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int i1 = 0;
int i2 = 0;
int iRes;

int main() {
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
		if (s1[i] == 'S')
			i1++;
	for (int i = 0; i < s2.size(); i++)
		if (s2[i] == 'S')
			i2++;
	iRes = i1 * i2;
	string res = "";
	for (int i = 0; i < iRes; i++)
		res += "S(";
	res += "0";
	for (int i = 0; i < iRes; i++)
		res += ")";
	cout << res << endl;
}
