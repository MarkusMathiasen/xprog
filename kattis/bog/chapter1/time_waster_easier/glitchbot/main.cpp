#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int n, dx, dy;
int xpos = 0, ypos = 0;
int dir = 0; // 0 = north; 1 = east; 2 = south; 3 = west;
vector<int> instructions;

bool sim(int itt) {
	if (itt == n)
		return xpos == dx && ypos == dy;
	int ins = instructions[itt];
	if (ins == 0) {
		if (dir == 0)
			ypos++;
		else if (dir == 1)
			xpos++;
		else if (dir == 2)
			ypos--;
		else if (dir == 3)
			xpos--;
		else
			throw dir;
	}
	else if (ins == 1) {
		dir--;
		if (dir < 0)
			dir += 4;
	}
	else if (ins == 2)
		dir = (dir+1)%4;
	else
		throw ins;
	return sim(itt+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> dx >> dy >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "Forward")
			instructions.push_back(0);
		else if (s == "Left")
			instructions.push_back(1);
		else if (s == "Right")
			instructions.push_back(2);
		else
			throw s;
	}
	int res = -1;
	for (int i = 0; i < n && res == -1; i++) {
		for (int j = 0; j < 3 && res == -1; j++) {
			instructions[i] = (instructions[i]+1)%3;
			if (sim(0))
				res = i;
			xpos = ypos = dir = 0;
		}
	}
	if (res == -1)
		throw res;
	string change;
	switch (instructions[res]) {
		case 0: change = "Forward"; break;
		case 1: change = "Left"; break;
		case 2: change = "Right"; break;
		default: throw instructions[res];
	}
	printf("%d %s\n", res+1, change.c_str());
	
}
