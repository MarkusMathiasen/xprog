#include <bits/stdc++.h>
using namespace std;
#define is pair<int, string>

int main() {
	string line; getline(cin, line);
	int n = stoi(line);
	vector<is> A;
	while (n--) {
		getline(cin, line);
		stringstream ss(line);
		string color; int r;
		if (isalpha(line[0]))
			ss >> color >> r;
		else {
			ss >> r >> color;
			r /= 2;
		}
		A.push_back(is(r, color));
	}
	sort(A.begin(), A.end());
	for (is p : A)
		cout << p.second << endl;
}
