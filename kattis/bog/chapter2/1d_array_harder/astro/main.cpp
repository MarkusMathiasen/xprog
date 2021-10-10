#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int toNum(int h, int m) {
	return h*60 + m;
}
ii toTime(int t) {
	return ii(t/60, t%60);
}

int a, b, inta, intb;
int sa, sb;
vector<string> dayName = {
	"Saturday",
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday"
};

bitset<3000000> bit(0);

int main() {
	int h, m;
	scanf("%d:%d", &h, &m);
	a = toNum(h, m);
	scanf("%d:%d", &h, &m);
	b = toNum(h, m);
	scanf("%d:%d", &h, &m);
	inta = toNum(h, m);
	scanf("%d:%d", &h, &m);
	intb = toNum(h, m);
	int modDay = toNum(24, 0);
	for (int x = a; x < 3000000; x += inta)
		bit.set(x);
	int res = -1;
	for (int x = b; x < 3000000; x += intb) {
		if (bit[x]) {
			res = x;
			break;
		}
	}
	if (res == -1)
		printf("Never\n");
	else {
		string day = dayName[(res/modDay)%7];
		ii tim = toTime(res%modDay);
		printf("%s\n%02d:%02d\n", day.c_str(), tim.first, tim.second);
	}
}
