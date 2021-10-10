#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define iii pair<ii, int>

int n, q;
int p[200001], sorted[200001], last[200001], ft[400001];
map<int, int> m;
iii Q[200000];
int results[200000];

int lsb(int i) {return i&(-i);}
void add(int p, int k){
	while (p <= n)
		ft[p] += k, p += lsb(p);
}
int sum(int p){
	int result = 0;
	while (p > 0)
		result += ft[p], p -= lsb(p);
	return result;
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]), sorted[i] = p[i];
	sort(&sorted[1], &sorted[n+1]);
	for (int i = 1; i <= n; i++)
		if (!m[p[i]])
			m[p[i]] = m.size()+1;
	for (int i = 0; i < q; i++)
		scanf("%d %d", &Q[i].first.second, &Q[i].first.first), Q[i].second = i;
	sort(&Q[0], &Q[q]);
	int qq = 0;
	for (int i = 1; i <= n; i++){
		int v = m[p[i]];
		if (last[v])
			add(last[v], -1);
		last[v] = i;
		add(i, 1);
		while (qq < q && Q[qq].first.first == i){
			int from = Q[qq].first.second;
			int to = Q[qq].first.first;
			results[Q[qq].second] = sum(to)-sum(from-1);
			qq++;
		}
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", results[i]);
}

