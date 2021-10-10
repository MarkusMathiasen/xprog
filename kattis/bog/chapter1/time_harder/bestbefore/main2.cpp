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
	if (v[1] > 12 || v[1] < 1)
		return false;
	if (v[2] < 1 || v[2] > days[v[1]-1] + isLeap(v[0], v[1]))
		return false;
	return true;
}

int main() {
	string s; cin >> s;
	int a, b, c;
	sscanf(s.c_str(), "%d/%d/%d", &a, &b, &c);
	vector<int> v = {a, b, c};
	sort(v.begin(), v.end());
	vector<vector<int>> res;
	do {
		if (check(v))
			res.push_back(v);
	} while (next_permutation(v.begin(), v.end()));
	sort(res.begin(), res.end());
	if (res.size() == 0)
		printf("%s is illegal\n", s.c_str());
	else
		printf("%d-%02d-%02d\n", f(res[0][0]), res[0][1], res[0][2]);
}
