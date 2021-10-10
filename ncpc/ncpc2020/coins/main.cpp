#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> stacks;

int main() {
	cin >> n;
	stacks.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> stacks[i];
	int sum = 0;
	int big = 0;

	for (int i = 0; i < n; i++) {
		sum += stacks[i];
		big = max(big, stacks[i]);
	}
	if (sum % 2 == 1 || big > sum / 2) {
		cout << "no" << endl;
		return 0;
	}
	cout << "yes" << endl;
	while (sum) {
		int first = 0;
		for (int i = 0; i < n; i++)
			if (stacks[i] > stacks[first])
				first = i;
		int second = first == 0 ? 1 : 0;
		for (int i = 0; i < n; i++) {
			if (i == first) continue;
			if (stacks[i] > stacks[second])
				second = i;
		}
		cout << first+1 << " " << second+1 << endl;
		stacks[first]--;
		stacks[second]--;
		sum -= 2;
	}

}
