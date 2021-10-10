#include <bits/stdc++.h>

using namespace std;

int n, q;
int p[200001], ft[400001];
vector<int> sorted;
map<int, int> m;
vector<vector<int>> queries;

int lsb(int i) {return i&(-i);}
void add(int p, int k){
	while (p <= (int)m.size())
		ft[p] += k, p += lsb(p);
}
int sum(int i){
	int res = 0;
	while (i > 0)
		res += ft[i], i -= lsb(i);
	return res;
}
int sum(int from, int to){return sum(to)-sum(from-1);}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]), sorted.push_back(p[i]);
	queries.assign(q, vector<int>(3, 0));
	for (int i = 0; i < q; i++){
		char o; int a, b; scanf(" %c %d %d", &o, &a, &b);
		if (o == '!'){
			sorted.push_back(b);
			queries[i][0] = 0;
		}
		else{
			queries[i][0] = 1;
		}
		queries[i][1] = a;
		queries[i][2] = b;
	}
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i < (int) sorted.size(); i++){
		if (sorted[i] == sorted[i-1]) continue;
		m[sorted[i]] = m.size()+1;
	}
	for (int i = 1; i <= n; i++)
		add(m[p[i]], 1);
	for (vector<int> Q : queries){
		if (Q[0] == 0){
			add(m[p[Q[1]]], -1);
			p[Q[1]] = Q[2];
			add(m[Q[2]], 1);
		}
		else {
			int from = (*(m.lower_bound(Q[1]))).second;
			int to = (*(--m.upper_bound(Q[2]))).second;
			printf("%d\n", sum(from, to));
		}
	}
}
