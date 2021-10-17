#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> pieces = {
	{ {0}, {0, 0, 0, 0} },
	{ {0, 0} },
	{ {0, 0, 1}, {1, 0} },
	{ {1, 0, 0}, {0, 1} },
	{ {0, 0, 0}, {0, 1}, {1, 0, 1}, {1, 0} },
	{ {0, 0, 0}, {0, 0}, {0, 1, 1}, {2, 0} },
	{ {0, 0, 0}, {0, 2}, {1, 1, 0}, {0, 0} }
};

int C, P;
vector<vector<int>> piece;
vector<int> level;

bool fit(int r, int pos) {
	vector<int> p = piece[r];
	if (pos + (int)p.size()-1 >= C)
		return false;
	bool res = true;
	for (int i = 1; i < (int)p.size(); i++)
		res &= level[i+pos] - level[i+pos-1] == p[i] - p[i-1];
	return res;
}

int main() {
	scanf("%d%d", &C, &P);
	piece = pieces[P-1];
	level.assign(C, 0);
	for (int i = 0; i < C; i++)
		scanf("%d", &level[i]);
	int res = 0;
	for (int rot = 0; rot < (int)piece.size(); rot++)
		for (int pos = 0; pos < C; pos++)
			res += fit(rot, pos);
	printf("%d\n", res);
}
