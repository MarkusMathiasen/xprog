#include <bits/stdc++.h>
using namespace std;

vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> mon =
	{"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
vector<string> week = 
	{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int f(string s, vector<string>& v) {
	for (int i = 0; i < (int)v.size(); i++)
		if (v[i] == s)
			return i;
	throw -1;
}

int main() {
	int d, m, w; string s;
	cin >> d >> s;
	m = f(s, mon);
	cin >> s;
	w = f(s, week);
	int day = 0;
	for (int i = 0; i < m; i++)
		day += days[i];
	day += d-1;
	int we = (day + w) % 7;
	if (day > 59) {
		if (we == 4 || we == 3)
			printf("not sure\n");
		else
			printf(":(\n");
	}
	else {
		if (we == 4)
			printf("TGIF\n");
		else
			printf(":(\n");
	}
}
