#include <bits/stdc++.h>
using namespace std;

struct pers {
	int s, p, f, o, order, score;
};

vector<int> buff;
int n; 
vector<int> points = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
vector<pers> p;

int getPoints(int rank) {
	if (rank > 29)
		return 0;
	return points[rank];
}

void emptyBuff() {
	int points = 0;
	for (int x : buff)
		points += getPoints(x);
	points = ceil((double)points / buff.size());
	for (int x : buff)
		p[x].score = (points+p[x].o);
	buff.clear();
}

int main() {
	scanf("%d", &n);
	p.assign(n, pers());
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", &p[i].s, &p[i].p, &p[i].f, &p[i].o), p[i].order = i;
	sort(p.begin(), p.end(), [](pers const& a, pers const& b) {
		if (a.s != b.s)
			return a.s > b.s;
		if (a.p != b.p)
			return a.p < b.p;
		return a.f < b.f;
	});
	buff.push_back(0);
	for (int i = 1; i < n; i++) {
		if (p[i].s != p[buff[0]].s || p[i].p != p[buff[0]].p || p[i].f != p[buff[0]].f)
			emptyBuff();
		buff.push_back(i);
	}
	emptyBuff();
	sort(p.begin(), p.end(), [](pers const& a, pers const& b) {
		return a.order < b.order;
	});
	for (pers& x : p)
		printf("%d\n", x.score);
}
