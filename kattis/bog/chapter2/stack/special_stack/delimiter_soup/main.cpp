#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d\n", &n);
	stack<char> s;
	int res = -1;
	for (int i = 0; i < n; i++) {
		char c; scanf("%c", &c);
		if (c == ' ')
			continue;
		else if (c == '(' || c == '[' || c == '{')
			s.push(c);
		else if (c == ')') {
			if (!s.size() || s.top() != '(') {
				res = i;
				s.push(c);
				break;
			}
			s.pop();
		}
		else if (c == ']') {
			if (!s.size() || s.top() != '[') {
				res = i;
				s.push(c);
				break;
			}
			s.pop();
		}
		else if (c == '}') {
			if (!s.size() || s.top() != '{') {
				res = i;
				s.push(c);
				break;
			}
			s.pop();
		}
	}
	if (res == -1)
		printf("ok so far\n");
	else
		printf("%c %d\n", s.top(), res);
}
