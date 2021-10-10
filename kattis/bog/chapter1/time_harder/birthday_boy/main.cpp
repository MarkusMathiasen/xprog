#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int n;
vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> bdays;

int conv1(int m, int d) {
	m--;
	int res = 0;
	for (int i = 0; i < m; i++)
		res += days[i];
	return res + d - 1;
}

ii conv2(int d) {
	d++;
	int m = 1;
	while (d > days[m-1]) {
		d -= days[m-1];
		m++;
	}
	return ii(m, d);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s >> s;
		int m, d; sscanf(s.c_str(), "%d-%d", &m, &d);
		bdays.push_back((conv1(m, d) + 65) % 365);
	}
	sort(bdays.begin(), bdays.end());
	int gapsize = 364 - bdays.back() + bdays[0];
	vector<int> cand = {bdays[0] == 0 ? 364 : bdays[0]-1};
	for (int i = 1; i < n; i++) {
		int gap = bdays[i] - bdays[i-1] -1;
		if (gap == gapsize)
			cand.push_back(bdays[i]-1);
		else if (gap > gapsize) {
			gapsize = gap;
			cand = {bdays[i]-1};
		}
	}
	sort(cand.begin(), cand.end());
	for (int& d : cand)
		d = (d+300) % 365;
	ii res = conv2(cand[0]);
	printf("%02d-%02d\n", res.first, res.second);
}
