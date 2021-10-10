#include <bits/stdc++.h>
using namespace std;

int toSec(int h, int m, int s) {
	return h*60*60 + m*60 + s;
}

vector<int> toTim(int s) {
	vector<int> res(3, 0);
	res[2] = s%60;
	s /= 60;
	res[1] = s%60;
	s /= 60;
	res[0] = s;
	return res;
}

int main() {
	int h, m, s; scanf("%d:%d:%d", &h, &m, &s);
	int t1 = toSec(h, m, s);
	scanf("%d:%d:%d", &h, &m, &s);
	int t2 = toSec(h, m, s);
	if (t2 < t1)
		t2 += 24*60*60;
	int t = t2-t1 % (24*60*60);
	if (t == 0)
		t = 24*60*60;
	vector<int> res = toTim(t);
	printf("%02d:%02d:%02d\n", res[0], res[1], res[2]);
}
