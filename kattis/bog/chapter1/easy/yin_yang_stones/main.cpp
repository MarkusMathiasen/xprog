#include <bits/stdc++.h>
using namespace std;

map<char, int> m;
char c;

int main() {
	while (scanf(" %c", &c) != EOF)
		m[c]++;
	printf("%d\n", m['B'] == m['W']);
}
