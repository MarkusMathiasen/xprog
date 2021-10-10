#include <bits/stdc++.h>
using namespace std;

multiset<char> s;

int main() {
	char c;
	while (scanf(" %c%*c", &c) != EOF)
		s.insert(c);
	int res = 0;
	for (char x : s)
		res = max(res, (int)s.count(x));
	printf("%d\n", res);
}
