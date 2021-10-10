#include <bits/stdc++.h>
using namespace std;

vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y, int m) {
	return (m == 2 && (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)));
}

int f(int x) {
	return x < 2000 ? x+2000 : x;
}

bool check(vector<int> v) {
	v[0] = f(v[0]);
	if (v[1] > 12)
		return false;
	if (v[2] > days[v[1]-1] + isLeap(v[0], v[1]))
		return false;
	return true;
}

int main() {
	string s;
	cin >> s;
	stringstream ss(s);
	bool valid = true;
	vector<int> v(3, 0);
	for (int& i : v) {
		ss >> i;
		ss.ignore();
		if (i < 0)
			valid = false;
		if (i == 0)
			i += 2000;
	}
	sort(v.begin(), v.end());
	vector<vector<int>> res;
	do {
		if (check(v))
			res.push_back(v);
	} while (next_permutation(v.begin(), v.end()));
	sort(res.begin(), res.end());
	if (res.size() == 0 || !valid)
		cout << s << " is illegal\n";
	else
		printf("%d-%02d-%02d\n", f(res[0][0]), res[0][1], res[0][2]);
}
