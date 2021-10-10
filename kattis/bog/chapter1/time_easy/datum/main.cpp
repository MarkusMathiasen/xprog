#include <bits/stdc++.h>
using namespace std;

vector<int> v = {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1};
vector<string> v2 = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
	int d, m; scanf("%d%d", &d, &m);
	int res = (v[m-1]+d-1)%7;
	cout << v2[res] << endl;
}
