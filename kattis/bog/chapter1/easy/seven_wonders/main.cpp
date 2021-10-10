#include <bits/stdc++.h>
using namespace std;

map<char, int> m;

int main() {
	char c;
	while (scanf(" %c", &c) != EOF)
		m[c]++;
	printf("%d\n", m['T']*m['T'] + m['C']*m['C'] + m['G']*m['G'] + min(min(m['T'], m['G']), m['C'])*7);
}
