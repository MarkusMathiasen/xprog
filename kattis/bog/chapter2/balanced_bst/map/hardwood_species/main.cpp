#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	map<string, int> m;
	int sum = 0;
	while (getline(cin, s) && s != "") {
		sum++;
		m[s]++;
	}
	for (auto& [k,v] : m)
		printf("%s %lf\n", k.c_str(), v*100/(double)sum);
}
