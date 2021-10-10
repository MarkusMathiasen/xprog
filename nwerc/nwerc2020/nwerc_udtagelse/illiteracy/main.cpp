#include <bits/stdc++.h>

using namespace std;
#define si pair<string, int>

string start;
string goal;

unordered_set<string> vis;

char rotate(char c) {
	if (c == 'F')
		return 'A';
	return c+1;
}

int main() {
	cin >> start >> goal;
	queue<si> Q;
	Q.push(si(start, 0));
	vis.insert(start);
	while (true) {
		string state = Q.front().first;
		int d = Q.front().second;
		Q.pop();
		if (state == goal) {
			cout << d << endl;
			return 0;
		}
		for (int pos = 0; pos < 8; pos++) {
			string s = state;
			if (s[pos] == 'A') {
				if (pos != 7)
					s[pos+1] = rotate(s[pos+1]);
				if (pos != 0)
					s[pos-1] = rotate(s[pos-1]);
			}
			else if (s[pos] == 'B') {
				if (pos == 0 || pos == 7)
					continue;
				s[pos+1] = s[pos-1];
			}
			else if (s[pos] == 'C') {
				s[7-pos] = rotate(s[7-pos]);
			}
			else if (s[pos] == 'D') {
				int i = pos < 4 ? 0 : pos+1;
				for (; i != pos && i != 8; i++)
					s[i] = rotate(s[i]);
			}
			else if (s[pos] == 'E') {
				if (pos == 0 || pos == 7)
					continue;
				if (pos < 4) {
					s[0] = rotate(s[0]);
					s[2*pos] = rotate(s[2*pos]);
				}
				else {
					s[7] = rotate(s[7]);
					s[2*pos-7] = rotate(s[2*pos-7]);
				}
			}
			else if (s[pos] == 'F') {
				pos++;
				if (pos % 2 == 1)
					s[(pos+9)/2 - 1] = rotate(s[(pos+9)/2 - 1]);
				else
					s[pos / 2 -1] = rotate(s[pos / 2 - 1]);
				pos--;
			}
			if (vis.count(s))
				continue;
			vis.insert(s);
			Q.push(si(s, d+1));
		}
	}
}

