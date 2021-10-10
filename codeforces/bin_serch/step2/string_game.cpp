#include <bits/stdc++.h>

using namespace std;

string t, p;
vector<int> ops(200000, 0);

bool checkNum(int x) {
	vector<bool> del(t.size(), false);
	for (int i = 0; i < x; i++)
		del[ops[i]] = true;
	int idx = 0;
	for (int i = 0; i < (int)t.size() && idx < (int)p.size(); i++) {
		if (del[i])
			continue;
		if (t[i] == p[idx])
			idx++;
	}
	return idx == (int) p.size();
}

int main() {
	cin >> t >> p;
	for (int i = 0; i < (int)t.size(); i++)
		scanf("%d", &ops[i]), ops[i]--;
	int lower = 1;
	int upper = t.size();
	while (lower < upper) {
		int mid = (lower + upper) / 2;
		if (checkNum(mid))
			lower = mid+1;
		else
			upper = mid;
	}
	printf("%d\n", lower-1);
}
