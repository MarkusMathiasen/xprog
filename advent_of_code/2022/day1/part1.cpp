#include <bits/stdc++.h>
using namespace std;

vector<int> n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	int sum = 0;
	while (getline(cin, line)) {
		if (line == "")
			n.push_back(sum),
			sum = 0;
		else
			sum += stoi(line);
	}
	n.push_back(sum);
	sort(n.rbegin(), n.rend());
	cout << n[0] + n[1] + n[2] << endl;
}
	

