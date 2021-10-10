#include <bits/stdc++.h>
using namespace std;

vector<int> v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year) {
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

bool legal(int year, int month, int date) {
	if (year > 2999 || year < 2000)
		return false;
	if (month > 12 || month < 1)
		return false;
	if (date > 31 || date < 1)
		return false;
	if (v[month-1] >= date)
		return true;
	if (isLeap(year) && month == 2 && date == 29)
		return true;
	return false;
}

int format(int n) {
	if (n < 100)
		return n+2000;
	return n;
}

int main() {
	int a, b, c; scanf("%d/%d/%d", &a, &b, &c);
	vector<int> vals = {a, b, c};
	vector<vector<int>> res;
	do {
		if (legal(format(vals[0]), vals[1], vals[2]))
			res.push_back(vals);
	}	while (next_permutation(vals.begin(), vals.end()));
	sort(res.begin(), res.end());
	if (res.size() == 0)
		printf("%d/%d/%d is illegal\n", a, b, c);
	else
		printf("%d-%02d-%02d\n", format(res[0][0]), res[0][1], res[0][2]);
}
