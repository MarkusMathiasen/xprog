#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define f first
#define s second

vector<ii> v = {ii(2, 1), ii(3, 1), ii(2, 2), ii(4, 1), ii(3, 2)};

int main() {

	sort(v.begin(), v.end(), [](ii a, ii b) {
		return a.f < b.f;
	});

	for (ii i : v)
		printf("%d %d\n", i.f, i.s);
	printf("\n");
}
