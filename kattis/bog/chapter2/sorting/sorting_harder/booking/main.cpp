#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

vector<int> m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int conv(int year, int month, int day, int hours, int minutes) {
	if (year == 2016 && month > 2)
		day++;
	day += (year-2013)*365;
	for (int i = 0; i < month-1; i++)
		day += m[i];
	hours += day*24;
	minutes += hours*60;
	return minutes;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int N, C; scanf("%d%d", &N, &C);
		vector<ii> tim;
		for (int i = 0; i < N; i++) {
			char c;
			while (scanf("%c", &c), c != ' ')
				continue;
			int year, month, day, hour, minute;
			scanf("%d-%d-%d %d:%d", &year, &month, &day, &hour, &minute);
			int t1 = conv(year, month, day, hour, minute);
			scanf("%d-%d-%d %d:%d", &year, &month, &day, &hour, &minute);
			int t2 = conv(year, month, day, hour, minute);
			tim.push_back(ii(t1, 1));
			tim.push_back(ii(t2+C, -1));
		}
		sort(tim.begin(), tim.end());
		int res = 0;
		int val = 0;
		for (ii p : tim) {
			val += p.second;
			res = max(res, val);
		}
		printf("%d\n", res);
	}
}
