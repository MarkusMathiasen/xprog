#include <bits/stdc++.h>
using namespace std;

string month;
int day, year;

void getTim(int& h, int& m) {
	string tim; cin >> tim;
	sscanf(tim.c_str(), "%d:%d", &h, &m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> month >> day >> year) {
		int h1, h2, m1, m2;
		getTim(h1, m1);
		getTim(h2, m2);
		int resh = h2 - h1;
		int resm = m2 - m1;
		if (resm < 0)
			resm += 60, resh--;
		printf("%s %d %d %d hours %d minutes\n", month.c_str(), day, year, resh, resm);
	}
}
