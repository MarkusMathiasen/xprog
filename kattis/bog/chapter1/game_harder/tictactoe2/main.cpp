#include <bits/stdc++.h>
using namespace std;

int t;
char grid[3][3];

bool wins(char c) {
	for (int i = 0; i < 3; i++) {
		bool row = true;
		bool col = true;
		for (int j = 0; j < 3; j++) {
			row &= grid[i][j] == c;
			col &= grid[j][i] == c;
		}
		if (row || col) return true;
	}
	bool dia1 = true, dia2 = true;
	for (int i = 0; i < 3; i++) {
		dia1 &= grid[i][i] == c;
		dia2 &= grid[i][2-i] == c;
	}
	return dia1 || dia2;
}

int count(char c) {
	int res = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			res += grid[i][j] == c;
	return res;
}

bool valid() {
	bool x = wins('X');
	bool o = wins('O');
	int cx = count('X');
	int co = count('O');
	if (cx == co)
		return !x;
	if (cx-1 == co)
		return !o;
	return false;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				scanf(" %c", &grid[i][j]);
		printf(valid() ? "yes\n" : "no\n");
	}
}
