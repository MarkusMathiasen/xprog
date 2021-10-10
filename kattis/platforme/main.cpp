#include <bits/stdc++.h>

using namespace std;

int N, res;
vector<vector<int>> p;

bool isUnder(int pos, int i){
	if (pos < p[i][1]) return false;
	if (pos > p[i][2]) return false;
	return true;
}

int main(){
	scanf("%d", &N);
	p.assign(N, vector<int>(3, 0));
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]), p[i][2]--;
	p.push_back({0, 0, 10000});	
	sort(p.begin(), p.end());
	for (int i = N; i > 0; i--){
		for (int pole = 1; pole < 3; pole++){
			for (int j = i-1; j >= 0; j--){
				if (isUnder(p[i][pole], j)){
					res += p[i][0]-p[j][0];
					break;
				}
			}
		}
	}
	printf("%d\n", res);
}
