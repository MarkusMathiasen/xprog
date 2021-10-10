#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n;
vector<ii> p;

int main(){
	scanf("%d", &n);
	while(n){
		p.assign(n, ii(0, 0));
		for (int i = 0; i < n; i++)
			scanf("%d %d", &p[i].first, &p[i].second);
		int X = p[n/2].first;
		int Y = p[n/2].second;
		int stan = 0;
		int ollie = 0;
		for (int i = 0; i < n; i++){
			int x = p[i].first;
			int y = p[i].second;
			if (x > X && y > Y) stan++;
			if (x > X && y < Y) ollie++;
			if (x < X && y > Y) ollie++;
			if (x < X && y < Y) stan++;
		}	
		printf("%d %d\n", stan, ollie);
		scanf("%d", &n);
	}
}
