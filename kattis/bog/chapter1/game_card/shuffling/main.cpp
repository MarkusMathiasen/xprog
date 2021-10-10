#include <bits/stdc++.h>
using namespace std;

int n;
string cmd;

vector<int> shuffle(vector<int>& v) {
	vector<int> res;
	for (int i = 0; i < n; i++) {
		if (cmd == "out") {
			if (i%2 == 0)
				res.push_back(v[i/2]);
			else
				res.push_back(v[(i-1)/2+ceil(n/2.0)]);
		}
		else {
			if (i%2 == 0)
				res.push_back(v[i/2+n/2]);
			else
				res.push_back(v[(i-1)/2]);
		}
	}
	return res;
}

int main() {
	cin >> n >> cmd;
	vector<int> start(n, 0);
	for (int i = 0; i < n; i++)
		start[i] = i;
	int res = 1;
	vector<int> v = shuffle(start);
	while (v != start)
		v = shuffle(v), res++;
	cout << res << endl;
}
