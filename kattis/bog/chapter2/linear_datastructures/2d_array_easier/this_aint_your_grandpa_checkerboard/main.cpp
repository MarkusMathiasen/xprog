#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	char board[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &board[i][j]);
	bool valid = true;
	for (int i = 0; i < n; i++) {
		int bs = 0, ws = 0;
		for (char c : board[i]) {
			if (c == 'B')
				bs++;
			else
				ws++;
		}
		valid &= bs == ws;
	}
	for (int j = 0; j < n; j++) {
		int bs = 0, ws = 0;
		for (int i = 0; i < n; i++) {
			char c = board[i][j];
			if (c == 'B')
				bs++;
			else
				ws++;
		}
		valid &= bs == ws;
	}
	for (int i = 0; i < n; i++) {
		char last = 'X';
		int cnt = 0;
		for (char c : board[i]) {
			if (c == last)
				cnt++;
			else
				cnt = 1;
			last = c;
			valid &= cnt < 3;
		}
	}
	for (int j = 0; j < n; j++) {
		char last = 'X';
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			char c = board[i][j];
			if (c == last)
				cnt++;
			else
				cnt = 1;
			last = c;
			valid &= cnt < 3;
		}
	}
	printf("%d\n", valid);
}
