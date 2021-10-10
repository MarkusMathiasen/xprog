#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> wins;
vector<int> loses;

bool f(string& m1, string& m2) {
	if (m1 == "rock")
		return m2 == "scissors";
	if (m1 == "paper")
		return m2 == "rock";
	if (m1 == "scissors")
		return m2 == "paper";
	return false; //should not reach this
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> k) {
		wins.assign(n+1, 0);
		loses.assign(n+1, 0);
		for (int i = 0; i < n*k*(n-1)/2; i++) {
			int p1, p2; string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2; 
			if (m1 == m2) continue;
			if (f(m1, m2))
				wins[p1]++, loses[p2]++;
			else
				wins[p2]++, loses[p1]++;
		}
		for (int i = 1; i <= n; i++)
			if (!(wins[i] + loses[i]))
				printf("-\n");
			else
				printf("%.3f\n", (double)wins[i] / (wins[i]+loses[i]));
		printf("\n");
	}
}
