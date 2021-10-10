#include <bits/stdc++.h>
using namespace std;

int t;
int w, h, n;
vector<vector<char>> p1, p2;
int p1Lives, p2Lives;
int shot;
vector<pair<int, int>> shots;

void fill(vector<vector<char>>& map, int& lives) {
	lives = 0;
	map.assign(w, vector<char>(h, '?'));
	for (int i = h-1; i >= 0; i--)
		for (int j = 0; j < w; j++) {
			scanf(" %c", &map[j][i]);
			lives += map[j][i] == '#';
		}
}

void turn(vector<vector<char>>& map, int& lives) {
	bool hit = true;
	int x, y;
	while (hit && lives && shot < (int)shots.size()) {
		x = shots[shot].first;
		y = shots[shot].second;
		shot++;
		if (map[x][y] == '_')
			hit = false;
		else {
			lives--;
			map[x][y] = '_';
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d\n", &w, &h, &n);
		fill(p1, p1Lives);
		fill(p2, p2Lives);
		shot = 0;
		shots.assign(n, {0, 0});
		for (int i = 0; i < n; i++)
			scanf("%d%d", &shots[i].first, &shots[i].second);
		while (p1Lives && p2Lives && shot < (int)shots.size()) {
			turn(p2, p2Lives);
			turn(p1, p1Lives);
		}
		if (p1Lives && !p2Lives)
			printf("player one wins\n");
		else if (p2Lives && !p1Lives)
			printf("player two wins\n");
		else
			printf("draw\n");
	}
}
