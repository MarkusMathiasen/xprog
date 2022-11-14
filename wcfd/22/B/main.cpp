#include <bits/stdc++.h>
using namespace std;

string prog;
int pp = 0, mp = 10000000;
char mem[20000000+5];
int jmp[10000005];

int main() {
	char c;
	while (scanf("%c", &c) != EOF)
		if (c == '<' || c == '>' || c == '+' || c == '-' || c == '.' || c == '[' || c == ']')
			prog.push_back(c);
	stack<int> open;
	for (int i = 0; i < (int)prog.size(); i++) {
		if (prog[i] == '[')
			open.push(i);
		if (prog[i] == ']') {
			jmp[i] = open.top();
			jmp[open.top()] = i;
			open.pop();
		}
	}
	while (pp >= 0 && pp < (int)prog.size()) {
		if (prog[pp] == '<') {
			mp--;
		} else if (prog[pp] == '>') {
			mp++;
		} else if (prog[pp] == '+') {
			mem[mp]++;
		} else if (prog[pp] == '-') {
			mem[mp]--;
		} else if (prog[pp] == '.') {
			printf("%c", mem[mp]);
		} else if (prog[pp] == '[') {
			if (mem[mp] == 0)
				pp = jmp[pp];
		} else if (prog[pp] == ']') {
			if (mem[mp] != 0)
				pp = jmp[pp]-1;
		} else assert(false);
		pp++;
	}
}
