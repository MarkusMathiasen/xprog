#include <bits/stdc++.h>
using namespace std;

int N;
int h, m;
string tim, ap, z1, z2;
map<string, int> v = {
	{"UTC", 0},
	{"GMT",	0},
	{"BST",	10},
	{"IST", 10},
	{"WET", 0},
	{"WEST", 10},
	{"CET", 10},
	{"CEST", 20},
	{"EET", 20},
	{"EEST", 30},
	{"MSK", 30},
	{"MSD", 40},
	{"AST", -40},
	{"ADT", -30},
	{"NST", -33},
	{"NDT", -23},
	{"EST", -50},
	{"EDT", -40},
	{"CST", -60},
	{"CDT", -50},
	{"MST", -70},
	{"MDT", -60},
	{"PST", -80},
	{"PDT", -70},
	{"HST", -100},
	{"AKST", -90},
	{"AKDT", -80},
	{"AEST", 100},
	{"AEDT", 110},
	{"ACST", 93},
	{"ACDT", 103},
	{"AWST", 80}
};

void to24() {
	cin >> tim;
	if (tim == "noon") {
		h = 12, m = 0;
		return;
	}
	if (tim == "midnight") {
		h = 0, m = 0;
		return;
	}
	cin >> ap;
	sscanf(tim.c_str(), "%d:%d", &h, &m);
	if (ap == "p.m." && h < 12) {
		h += 12;
		return;
	}
	if (ap == "a.m." && h == 12) {
		h -= 12;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--) {
		h = m = 0;
		to24();
		cin >> z1 >> z2;
		h -= v[z1]/10;
		m -= (v[z1]%10)*10;
		h += v[z2]/10;
		m += (v[z2]%10)*10;
		while (m < 0)
			m += 60, h--;
		while (m > 59)
			m -= 60, h++;
		while (h < 0)
			h += 24;
		while (h > 23)
			h -= 24;
		if (h == 0 && m == 0) {
			printf("midnight\n");
			continue;
		}
		else if (h == 12 && m == 0) {
			printf("noon\n");
			continue;
		}
		if (h >= 12)
			ap = "p.m.";
		else
			ap = "a.m.";
		if (h == 0)
			h += 12;
		if (h > 12)
			h -= 12;
		printf("%d:%02d %s\n", h, m, ap.c_str());
	}
}
