#include <bits/stdc++.h>
using namespace std;

vector<string> res;
vector<vector<int>> dp(600, vector<int>(3, -1));

bool foo(int t, int k) {
	if (k == -1 || t <= 0)
		return false;
	if (dp[t][k] != -1)
		return dp[t][k];
	if (t == 50) {
		res.push_back("bullseye");
		return (dp[t][k] = true);
	}
	for (int i = 1; i <= 20; i++) {
		if (t == 2*i) {
			res.push_back("double " + to_string(i));
			return (dp[t][k] = true);
		}
	}
	for (int i = 1; i <= 20; i++) {
		if (foo(t-i, k-1)) {
			res.push_back("single " + to_string(i));
			return (dp[t][k] = true);
		}
		if (foo(t-i*2, k-1)) {
			res.push_back("double " + to_string(i));
			return (dp[t][k] = true);
		}
		if (foo(t-i*3, k-1)) {
			res.push_back("triple " + to_string(i));
			return (dp[t][k] = true);
		}
	}
	if (foo(t-25, k-1)) {
		res.push_back("single bull");
		return (dp[t][k] = true);
	}
	if (foo(t-50, k-1)) {
		res.push_back("bullseye");
		return (dp[t][k] = true);
	}
	return (dp[t][k] = false);
}

int main() {
	int T; scanf("%d", &T);
	if (!foo(T, 2)) {
		printf("impossible\n");
		return 0;
	}
	for (int i = res.size()-1; i >= 0; i--)
		printf("%s\n", res[i].c_str());
}
