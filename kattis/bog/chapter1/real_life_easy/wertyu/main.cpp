#include <bits/stdc++.h>
using namespace std;

vector<char> board = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\',
'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};

char c;
int main() {
	while (scanf("%c", &c) != EOF)
		if (c == ' ' || c == '\n')
			printf("%c", c);
		else
			printf("%c", *(--find(board.begin(), board.end(), c)));
}
