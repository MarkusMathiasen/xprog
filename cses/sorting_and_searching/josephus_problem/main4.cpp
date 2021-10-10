#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

int n, k;
ordered_set s;

int main() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++)
		s.insert(i);
	int pos = 0;
	while (!s.empty()) {
		pos = (pos + k) % s.size();
		printf("%d ", *s.find_by_order(pos));
		s.erase(s.find_by_order(pos));
	}
	printf("\n");
}
