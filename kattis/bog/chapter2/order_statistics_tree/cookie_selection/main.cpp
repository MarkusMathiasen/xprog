#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
	string s;
	ost A;
	while (cin >> s) {
		if (s == "#") {
			auto it = A.find_by_order(A.size()/2);
			printf("%d\n", *it);
			A.erase(it);
		} else {
			int x = stoi(s);
			A.insert(x);
		}
	}
}
