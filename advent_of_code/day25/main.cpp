#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> floor;
	string s;
	while (getline(cin, s) && s != "")
		floor.push_back(s);
	bool moved = true;
	int steps;
	for (steps = 0; moved; steps++) {
		moved = false;
		for (string& row : floor) {
			bool moveLast = row[0] == '.' && row.back() == '>';
			for (int i = 0; i < (int)row.size()-1; i++)
				if (row[i] == '>' && row[i+1] == '.')
					row[i] = '.', row[i+1] = '>', i++, moved = true;
			moved |= moveLast;
			if (moveLast)
				row[0] = '>', row.back() = '.';
		}
		for (int col = 0; col < (int)floor[0].size(); col++) {
			bool moveLast = floor[0][col] == '.' && floor.back()[col] == 'v';
			for (int row = 0; row < (int)floor.size()-1; row++)
				if (floor[row][col] == 'v' && floor[row+1][col] == '.')
					floor[row+1][col] = 'v', floor[row][col] = '.', row++, moved = true;
			moved |= moveLast;
			if (moveLast)
				floor[0][col] = 'v', floor.back()[col] = '.';
		}
	}
	printf("%d\n", steps);
}
