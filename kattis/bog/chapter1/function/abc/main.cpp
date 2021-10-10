#include <bits/stdc++.h>
using namespace std;

vector<int> n(3, 0);

int main() {
	cin >> n[0] >> n[1] >> n[2];
	sort(n.begin(), n.end());
	string s; cin >> s;
	for (char c : s)
		printf("%d ", n[c-65]);
	printf("\n");
}
