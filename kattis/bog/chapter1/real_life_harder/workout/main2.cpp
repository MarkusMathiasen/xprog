#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

vector<ii> jim(10, ii()), mac(10, ii());
vector<int> tim(10, 0);

int f(int m, int t) {
	int tot = mac[m].first + mac[m].second;
	int jimDone;
	if (tim[m] <= t) {
		tim[m] += ((t-tim[m])/tot)*tot;
		jimDone = max(t, tim[m]+mac[m].first)+jim[m].first;
		tim[m] = max(jimDone, tim[m]+tot);
	}
	else {
		jimDone = t + jim[m].first;
		tim[m] = max(jimDone, tim[m]);
	}
	return jimDone + jim[m].second;
}

int main() {
	for (int i = 0; i < 10; i++)
		scanf("%d%d", &jim[i].first, &jim[i].second);
	for (int i = 0; i < 10; i++)
		scanf("%d%d%d", &mac[i].first, &mac[i].second, &tim[i]);
	int t = 0;
	for (int j = 0; j < 3; j++)
		for (int m = 0; m < 10; m++)
			t = f(m, t);
	printf("%d\n", t-jim[9].second);
}
