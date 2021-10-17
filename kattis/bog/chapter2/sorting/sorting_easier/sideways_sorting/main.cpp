#include <bits/stdc++.h>
using namespace std;

int r, c;

int main() {
	while (scanf("%d%d", &r, &c), r && c) {
		vector<string> res(c, "");
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				char c; scanf(" %c", &c);
				res[j].push_back(c);
			}
		stable_sort(res.begin(), res.end(), [](string a, string b) {
			for (char& c : a)
				c = tolower(c);
			for (char& c : b)
				c = tolower(c);
			return a < b;
		});
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				printf("%c", res[j][i]);
			printf("\n");
		}
		printf("\n");
	}
}
