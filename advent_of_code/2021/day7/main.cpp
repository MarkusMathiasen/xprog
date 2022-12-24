#include <bits/stdc++.h>
using namespace std;

vector<int> crabs;

int cost(int pos) {
	int res = 0;
	for (int x : crabs) {
		int dx = abs(x-pos);
		res += dx*(dx+1)/2;
	}
	return res;
}

int main() {
	int x;
	while (scanf("%d,", &x) != EOF)
		crabs.push_back(x);
	int bestCost = 1e9;
	for (int i = 0; i <= 1000; i++)
		bestCost = min(bestCost, cost(i));
	printf("%d\n", bestCost);
}
