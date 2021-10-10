#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;
string line;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (getline(cin, line)) {
		vector<vector<char>> v((int)line.size(), vector<char>());
		do {
			for (int i = 0; i < (int)v.size(); i++)
				v[i].push_back(line[i]);
		} while (getline(cin, line) && line != "");
		sort(v.rbegin(), v.rend());
		for (int j = 0; j < (int)v[0].size(); j++) {
			for (int i = 0; i < (int)v.size(); i++)
				printf("%c", v[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}
