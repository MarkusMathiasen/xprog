#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> A;

bool startx(int x, int y) {
	if (x == 0)
		return true;
	if (A[x-1][y] == '#')
		return true;
	return false;
}
bool starty(int x, int y) {
	if (y == 0)
		return true;
	if (A[x][y-1] == '#')
		return true;
	return false;
}
string readx(int x, int y) {
	string res = "";
	while (x < n && A[x][y] != '#')
		res.push_back(A[x][y]), x++;
	return res;
}
string ready(int x, int y) {
	string res = "";
	while (y < m && A[x][y] != '#')
		res.push_back(A[x][y]), y++;
	return res;
	
}

int main() {
	scanf("%d%d", &n, &m);
	A.assign(n, vector<char>(m, ' '));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &A[i][j]);
	vector<string> res;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (startx(i, j)) {
				string s = readx(i, j);
				if ((int)s.size() > 1)
					res.push_back(s);
			}
			if (starty(i, j)) {
				string s = ready(i, j);
				if ((int)s.size() > 1)
					res.push_back(s);
			}
		}
	sort(res.begin(), res.end());
	printf("%s\n", res[0].c_str());
}
