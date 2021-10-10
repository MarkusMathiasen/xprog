#include <bits/stdc++.h>
using namespace std;

char board[9][9];

void printsep() {
	for (int i = 0; i < 8; i++)
		printf("+---");
	printf("+\n");
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			board[i][j] = '?';
	string s;
	getline(cin, s);
	stringstream ss(s);
	getline(ss, s, ' ');
	while (getline(ss, s, ',')) {
		int x = s.back() - '0';
		int y = s[s.size()-2]-'a'+1;
		char p;
		if (s.size() == 2)
			p = 'P';
		else
			p = toupper(s[0]);
		board[x][y] = p;
	}
	getline(cin, s);
	ss.clear();
	ss.str(s);
	getline(ss, s, ' ');
	while (getline(ss, s, ',')) {
		int x = s.back() - '0';
		int y = s[s.size()-2]-'a'+1;
		char p;
		if (s.size() == 2)
			p = 'p';
		else
			p = tolower(s[0]);
		board[x][y] = p;
	}
	for (int i = 8; i >= 1; i--) {
		printsep();
		for (int j = 1; j <= 8; j++) {
			char mid;
			if ((i+j)%2 == 1)
				mid = '.';
			else
				mid = ':';
			printf("|%c", mid);
			if (board[i][j] == '?')
				printf("%c%c", mid, mid);
			else
				printf("%c%c", board[i][j], mid);
		}
		printf("|\n");
	}
	printsep();
}
