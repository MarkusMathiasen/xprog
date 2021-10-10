#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int res = 0;
int n;
map<string, int> m1;
map<int, string> m2;
vector<int> loves;
vector<int> loners;

bool rel(int a) {
	return loves[loves[a]] == a && loves[a] != a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	loves.assign(n+1, 0);
	vector<int> adm(n+1, 0);
	int count = 1;
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		if (m1[a] == 0) {
			m1[a] = count;
			m2[count++] = a;
		}
		if (m1[b] == 0) {
			m1[b] = count;
			m2[count++] = a;
		}
		loves[m1[a]] = m1[b];
		adm[m1[b]]++;
	}
	if (n % 2 != 0) {
		printf("-1\n");
		return 0;
	}
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	for (int i = 1; i <= n; i++)
		Q.emplace(adm[i], i);
	loners.assign(n+1, 0);
	while (!Q.empty()) {
		int v = Q.top().second;
		Q.pop();
		if (loves[v] == v) {
			loners[v] = 1;
			continue;
		}
		if (rel(v))
			continue;
		if (rel(loves[v])) {
			loners[v] = 1;
			continue;
		}
		adm[loves[loves[v]]]--;
		Q.emplace(adm[loves[loves[v]]], loves[loves[v]]);
		res++;
		loves[loves[v]] = v;
	}
	int sum = 0;
	for (int l : loners)
		sum += l;
	printf("%d\n", res + sum);
}
