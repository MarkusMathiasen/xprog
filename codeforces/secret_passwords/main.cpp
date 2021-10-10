#include <bits/stdc++.h>

using namespace std;

int n, groupCount;
int uf[26], r[26];
int used[26];
vector<int> S[200000];
int seen[26];
int result = 0;

int find(int i){
	if (uf[i] == i) return i;
	return uf[i] = find(uf[i]);
}
void group(int i, int j){
	int x = find(i); int y = find(j);
	if (x == y) return;
	if (r[x] > r[y]) uf[y] = x;
	else {
		if (r[x] == r[y]) r[y]++;
		uf[x] = y;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < 26; i++)
		uf[i] = i;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		S[i].assign(s.size(), 0);
		for (int j = 0; j < (int)s.size(); j++)
			S[i][j] = s[j]-97, seen[s[j]-97] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 1; j < (int)S[i].size(); j++)
			group(S[i][j], S[i][j-1]);
	for (int i = 0; i < 26; i++){
		if (!seen[i]) continue;
		if (used[find(i)]) continue;
		used[find(i)] = 1;
		result++;
	}
	printf("%d\n", result);
}
