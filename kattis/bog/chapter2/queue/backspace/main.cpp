#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	vector<char> s;
	while (scanf("%c", &c), c != '\n') {
		if (c == '<')
			s.pop_back();
		else
			s.push_back(c);
	}
	for (char x : s)
		printf("%c", x);
	printf("\n");
}
