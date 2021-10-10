#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

vector<ii> jim(10, ii()), mac(10, ii());
vector<int> pers(10, 0);
int act = 0;
int machine;

void persUpdate() {
	for (int i = 0; i < 10; i++) {
		if (pers[i] == 0) {
			if (act >= -1 || machine != i)
				pers[i] = -mac[i].first;
		}
		else if (pers[i] == -1)
			pers[i] = mac[i].second-1;
		else if (pers[i] < 0)
			pers[i]++;
		else
			pers[i]--;
	}
}

bool jimUpdate(int m) {
	if (pers[m] < 0 && act == 0)
		return true;
	else if (act == 0)
		return (act = -jim[m].first);
	else if (act == -1)
		return (act = jim[m].second-1);
	else if (act < 0)
		return (act = act+1);
	else
		return (act = act-1);
}

int main() {
	for (int i = 0; i < 10; i++)
		scanf("%d%d", &jim[i].first, &jim[i].second);
	for (int i = 0; i < 10; i++)
		scanf("%d%d%d", &mac[i].first, &mac[i].second, &pers[i]);
	int res = 0;
	for (int j = 0; j < 3; j++) {
		for (machine = 0; machine < 10; machine++) {
			res++;
			persUpdate();
			if (jimUpdate(machine))
				machine--;
		}
	}

	printf("%d\n", res - jim[9].second);
}
