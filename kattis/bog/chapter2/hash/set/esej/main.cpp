#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b; scanf("%d%d", &a, &b);
	string s = "abcdefghijklmnp";
	for (int i = 0; i < max((b+1)/2, a); i++) {
		printf("%s ", s.c_str());
		next_permutation(s.begin(), s.end());
	}
	printf("\n");
}
