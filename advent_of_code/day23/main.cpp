#include <bits/stdc++.h>
using namespace std;
typedef pair<int, vector<string>> que;

set<vector<string>> states = {
	{
		"...........",
		"BCBD",
		"DCBA",
		"DBAC",
		"ADCA"
	},
	{
		"..........D",
		"BCB.",
		"DCBA",
		"DBAC",
		"ADCA"
	},
	{
		"A.........D",
		"BCB.",
		"DCB.",
		"DBAC",
		"ADCA"
	},
	{
		"A........BD",
		"BC..",
		"DCB.",
		"DBAC",
		"ADCA"
	},
	{
		"A......B.BD",
		"BC..",
		"DC..",
		"DBAC",
		"ADCA"
	},
	{
		"AA.....B.BD",
		"BC..",
		"DC..",
		"DB.C",
		"ADCA"
	},
	{
		"AA.....B.BD",
		"B...",
		"DC..",
		"DBCC",
		"ADCA"
	},
	{
		"AA.....B.BD",
		"B...",
		"D.C.",
		"DBCC",
		"ADCA"
	},
	{
		"AA...B.B.BD",
		"B...",
		"D.C.",
		"D.CC",
		"ADCA"
	},
	{
		"AA.D.B.B.BD",
		"B...",
		"D.C.",
		"D.CC",
		"A.CA"
	},
	{
		"AA.D...B.BD",
		"B...",
		"D.C.",
		"D.CC",
		"ABCA"
	},
	{
		"AA.D.....BD",
		"B...",
		"D.C.",
		"DBCC",
		"ABCA"
	},
	{
		"AA.D......D",
		"B...",
		"DBC.",
		"DBCC",
		"ABCA"
	},
	{
		"AA.D......D",
		"B.C.",
		"DBC.",
		"DBC.",
		"ABCA"
	},
	{
		"AA.D.....AD",
		"B.C.",
		"DBC.",
		"DBC.",
		"ABC."
	},
	{
		"AA.......AD",
		"B.C.",
		"DBC.",
		"DBC.",
		"ABCD"
	},
	{
		"AA.......AD",
		".BC.",
		"DBC.",
		"DBC.",
		"ABCD"
	},
	{
		"AA.......AD",
		".BC.",
		".BC.",
		"DBCD",
		"ABCD"
	},
	{
		"AA.D.....AD",
		".BC.",
		".BC.",
		".BCD",
		"ABCD"
	},
	{
		"A..D.....AD",
		".BC.",
		".BC.",
		"ABCD",
		"ABCD"
	},
	{
		"...D.....AD",
		".BC.",
		"ABC.",
		"ABCD",
		"ABCD"
	},
	{
		".........AD",
		".BC.",
		"ABCD",
		"ABCD",
		"ABCD"
	},
	{
		"..........D",
		"ABC.",
		"ABCD",
		"ABCD",
		"ABCD"
	},
	{
		"...........",
		"ABCD",
		"ABCD",
		"ABCD",
		"ABCD"
	},
};

const int rowCnt = 4;

int dis(int top, int col, int row) {
	return abs(top - (col+1)*2) + row;
}

int firstRow(vector<string>& s, int col) {
	int row = 1;
	while (row <= rowCnt && s[row][col] == '.')
		row++;
	return row;
}

int clear(vector<string>& s, int col) {
	char c = col+'A';
	int row = firstRow(s, col);
	bool res = true;
	for (int i = row; i <= rowCnt; i++)
		res &= s[i][col] == c;
	return res ? row-1 : -1;
}

bool path(vector<string>& s, int topPos, int col) {
	bool res = true;
	for (int i = topPos+1; i <= (col+1)*2; i++)
		res &= s[0][i] == '.';
	for (int i = (col+1)*2; i < topPos; i++)
		res &= s[0][i] == '.';
	return res;
}

int modi(char c) {
	int res = 1;
	for (int i = 'A'; i < c; i++)
		res *= 10;
	return res;
}

int reduce(vector<string>& s) {
	int res = 0;
	for (int i = 0; i < (int)s[0].size(); i++)
		if (s[0][i] != '.') {
			int col = s[0][i]-'A';
			int row = clear(s, col);
			if (row != -1) {
				bool hasPath = path(s, i, col);
				if (hasPath) {
					int mod = modi(s[0][i]);
					res += dis(i, col, row)*mod;
					s[row][col] = s[0][i];
					s[0][i] = '.';
				}
			}
		}
	return res;
}

int main() {
	vector<string> v = {"...........", "CDDA", "DCBA", "DBAC", "BABC"};
	map<vector<string>, int> dist;
	priority_queue<que, vector<que>, greater<que>> pq;
	pq.push(que(0, v));
	while (!pq.empty()) {
		auto [d,s] = pq.top(); pq.pop();
		if (dist.count(s))
			continue;
		dist[s] = d;
		int red = reduce(s);
		if (red) {
			pq.push(que(d+red, s));
			continue;
		}

		for (int col = 0; col < 4; col++) {
			if (clear(s, col) != -1)
				continue;
			for (int i = 0; i < (int)s[0].size(); i++) {
				if (s[0][i] != '.' || i == 2 || i == 4 || i == 6 || i == 8)
					continue;
				if (path(s, i, col)) {
					int row = firstRow(s, col);
					if (row == rowCnt+1)
						continue;
					s[0][i] = s[row][col];
					s[row][col] = '.';
					int cost = dis(i, col, row)*modi(s[0][i]);
					if (s == vector<string>{"AA.D.B.BB.D", "B...", "D.C.", "D.CC", "A.CA"})
						printf("found\n");
					pq.push(que(d+cost, s));
					s[row][col] = s[0][i];
					s[0][i] = '.';
				}
			}
		}
	}
	printf("%d\n", dist[vector<string>{"...........", "ABCD", "ABCD", "ABCD", "ABCD"}]);
}
