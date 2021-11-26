#include <bits/stdc++.h>
using namespace std;

string solutions[2000001];

int solve(string s) {
	vector<int> v = {4, 4, 4, 4};
	auto it2 = v.begin();
	for (auto it = s.begin(); it != s.end();)
		if (*it == '*')
			*it2 *= *(it2+1),
			v.erase(it2+1),
			s.erase(it);
		else if (*it == '/')
			*it2 /= *(it2+1),
			v.erase(it2+1),
			s.erase(it);
		else
			it2++,
			it++;
	while (s.size()) {
		if (s[0] == '+')
			v[0] += v[1];
		else
			v[0] -= v[1];
		s.erase(s.begin());
		v.erase(++v.begin());
	}
	return v[0];
}

int to_char(int x) {
	if (x == 0)
		return '+';
	if (x == 1)
		return '-';
	if (x == 2)
		return '*';
	if (x == 3)
		return '/';
	throw x;
}

int mil = 1000000;

void genSolutions() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++) {
				string s;
				s.push_back(to_char(i));
				s.push_back(to_char(j));
				s.push_back(to_char(k));
				solutions[solve(s)+mil] = s;
			}
}

int main() {
	for (int i = 0; i < 2000001; i++)
		solutions[i] = "";
	genSolutions();
	int m; scanf("%d", &m);
	while (m--) {
		int n; scanf("%d", &n);
		if (solutions[n+mil] == "")
			printf("no solution\n");
		else
			printf("4 %c 4 %c 4 %c 4 = %d\n", solutions[n+mil][0], solutions[n+mil][1], solutions[n+mil][2], n);
	}
}
