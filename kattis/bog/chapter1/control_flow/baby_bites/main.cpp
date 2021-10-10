#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
	cin >> n;
	bool fishy = false;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (s == "mumble")
			continue;
		if (stoi(s) != i)
			fishy = true;
	}
	if (fishy)
		printf("something is fishy\n");
	else
		printf("makes sense\n");
}
