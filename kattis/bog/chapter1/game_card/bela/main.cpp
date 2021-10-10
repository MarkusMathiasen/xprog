#include <bits/stdc++.h>
using namespace std;

map<char, int> points = {
	{'A', 11},
	{'K', 4},
	{'Q', 3},
	{'J', 2},
	{'T', 10},
	{'9', 0},
	{'8', 0},
	{'7', 0}};
map<char, int> dominant = {
	{'A', 11},
	{'K', 4},
	{'Q', 3},
	{'J', 20},
	{'T', 10},
	{'9', 14},
	{'8', 0},
	{'7', 0}};
int N, res = 0;
char B;
int main() {
	scanf("%d %c\n", &N, &B);
	for (int i = 0; i < 4*N; i++) {
		char v, b; scanf(" %c%c", &v, &b);
		if (b == B)
			res += dominant[v];
		else
			res += points[v];
	}
	printf("%d\n", res);
}
