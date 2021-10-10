/*
ID: markus3
TASK: camelot
LANG: C++                 
*/
#include <bits/stdc++.h>
using namespace std;

ofstream fout ("camelot.out");
ifstream fin ("camelot.in");
#define ii pair<int, int>

struct state{
	int r;
	int c;
	int d;
};

int R, C;
ii king;
vector<ii> knights;
int dist[30][26][30][26];
int result = INT_MAX;

bool isValid(int a, int b){
	if (a >= R || a < 0) return false;
	if (b >= C || b < 0) return false;
	return true;
}
int kingDist(int x, int y){
	return max(abs(king.first - x), abs(king.second - y));
}
int knightDist(int h, int midx, int midy, int x, int y){
	int a = knights[h].first; int b = knights[h].second;
	int res = dist[a][b][midx][midy];
	return res+dist[midx][midy][x][y];
}

int main() {
	fin >> R >> C;
	char c;int r;
	fin >> c >> r; c-= 65; r--;
	king = {r, (int)c};
	while (fin >> c >> r)
		c -= 65, r--, knights.push_back(ii(r, (int)c));

	for (int a = 0; a < 30; a++)
		for (int b = 0; b < 26; b++)
			for (int c = 0; c < 30; c++)
				for (int d = 0; d < 26; d++)
					dist[a][b][c][d] = -1;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++){
			queue<state> Q;
			Q.push({i, j, 0});
			while (!Q.empty()){
				state s = Q.front(); Q.pop();
				if (!isValid(s.r, s.c)) continue;
				if (dist[i][j][s.r][s.c] != -1) continue;
				dist[i][j][s.r][s.c] = s.d;
				s.d++;
				Q.push({s.r+2, s.c+1, s.d});
				Q.push({s.r+2, s.c-1, s.d});
				Q.push({s.r-2, s.c+1, s.d});
				Q.push({s.r-2, s.c-1, s.d});
				Q.push({s.r+1, s.c+2, s.d});
				Q.push({s.r-1, s.c+2, s.d});
				Q.push({s.r+1, s.c-2, s.d});
				Q.push({s.r-1, s.c-2, s.d});
			}
		}
	if (knights.size() == 0){
		fout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++){
			int best = INT_MAX;
			for (int a = king.first-2; a < king.first+3; a++)
				for (int b = king.second-2; b < king.second+3; b++){
					if (!isValid(a, b)) continue;
					for (int h = 0; h < (int)knights.size(); h++){
						if (dist[knights[h].first][knights[h].second][a][b] < 0)
							continue;
						if (dist[a][b][i][j] < 0) continue;
						int d = knightDist(h, a, b, i, j) + kingDist(a, b)
							- dist[knights[h].first][knights[h].second][i][j];
						best = min(best, d);
					}
				}
			int attempt = best;
			int possible = 1;
			for (int k = 0; k < (int)knights.size(); k++){
				if (dist[knights[k].first][knights[k].second][i][j] < 0) possible = false;
				attempt += dist[knights[k].first][knights[k].second][i][j];
			}
			if (!possible) continue;
			result = min(result, attempt);
			attempt -= best;
			result = min(result, attempt+kingDist(i, j));
		}
	fout << result << endl;
}
