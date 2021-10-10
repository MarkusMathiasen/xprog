#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> bigG[501], smallG[501];
map<int, int> ends;
vector<int> found;


int main(){
	scanf("%d %d", &n, &m);
	while (m--){
		int a, b; scanf("%d %d", &a, &b);
		bigG[a].push_back(b);
		if (b == n) ends[a] = ends.size();
	}
	for (int i = 0; i < (int)bigG[0].size(); i++){
		found.assign(0);
		int start = bigG[0][i];
		vector<int>
		queue<int> Q
	}
}
