#include <bits/stdc++.h>
using namespace std;

struct light {
	int p;
	int r;
	int g;
};

int N, L;
vector<light> lights;

int main() {
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++) {
		light l; scanf("%d%d%d", &l.p, &l.r, &l.g);
		lights.push_back(l);
	}
	int tim = 0;
	int prev = 0;
	for (light l : lights) {
		tim += l.p - prev, prev = l.p;
		int cyc = tim % (l.g + l.r);
		tim += max(0, l.r-cyc);
	}
	printf("%d\n", tim + L - prev);
}
