#include <bits/stdc++.h>
using namespace std;

int X = 1400;
int Y = 1400;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> paper(X, vector<int>(X, 0));
	string s;
	while (getline(cin, s) && s != "") {
		int x, y;
		sscanf(s.c_str(), "%d,%d", &x, &y);
		paper[y][x] = 1;
	}
	char c; int d;
	while (cin >> s >> s >> s) {
		sscanf(s.c_str(), "%c=%d", &c, &d);
		if (c == 'x') {
			for (int y = 0; y < Y; y++)
				for (int x = 1; x <= d && x+d < X; x++)
					paper[y][d-x] |= paper[y][d+x];
			X = d;
		}
		else if (c == 'y') {
			for (int y = 1; y <= d && d+y < Y; y++)
				for (int x = 0; x < X; x++)
					paper[d-y][x] |= paper[d+y][x];
			Y = d;
		}
		else throw c;
	}
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++)
			printf(paper[y][x] ? "#" : ".");
		printf("\n");
	}
}
