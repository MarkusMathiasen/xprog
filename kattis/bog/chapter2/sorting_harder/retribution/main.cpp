#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

struct que {
	int dist;
	int judge;
	int rep;
	que(double dist, int judge, int rep) {
		this->dist = dist;
		this->judge = judge;
		this->rep = rep;
	}
	bool operator<(que const& b) const {
		if (dist != b.dist)
			return dist < b.dist;
		if (judge != b.judge)
			return judge < b.judge;
		return rep < b.rep;
	}
};

int sqr(int x) {return x*x;}

int main() {
	int n, m, p; scanf("%d%d%d", &n, &m, &p);
	vector<point> judges(n, point()), tars(m, point()), feathers(p, point());
	for (int i = 0; i < n; i++)
		scanf("%d%d", &judges[i].x, &judges[i].y);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &tars[i].x, &tars[i].y);
	for (int i = 0; i < p; i++)
		scanf("%d%d", &feathers[i].x, &feathers[i].y);
	vector<que> A, B;
	for (int i = 0; i < n; i++) {
		point& j = judges[i];
		for (int k = 0; k < m; k++) {
			point& t = tars[k];
			A.push_back(que(sqr(j.x-t.x)+sqr(j.y-t.y), i, k));
		}
		for (int k = 0; k < p; k++) {
			point& t = feathers[k];
			B.push_back(que(sqr(j.x-t.x)+sqr(j.y-t.y), i, k));
		}
	}
	stable_sort(A.begin(), A.end());
	stable_sort(B.begin(), B.end());
	double res = 0;
	bitset<1000> hj(0);
	bitset<1000> ht(0);
	for (que q : A)
		if (!hj[q.judge] && !ht[q.rep]) {
			hj.set(q.judge);
			ht.set(q.rep);
			res += sqrt(q.dist);
		}
	hj.reset();
	ht.reset();
	for (que q : B)
		if (!hj[q.judge] && !ht[q.rep]) {
			hj.set(q.judge);
			ht.set(q.rep);
			res += sqrt(q.dist);
		}
	printf("%lf\n", res);
}
