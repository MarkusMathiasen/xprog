#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cmd;
	ost girls, boys;
	while (cin >> cmd) {
		if (cmd == 0)
			break;
		else if (cmd == 1) {
			string name; int gender; cin >> name >> gender;
			if (gender == 1)
				boys.insert(name);
			else if (gender == 2)
				girls.insert(name);
			else throw gender;
		}
		else if (cmd == 2) {
			string name; cin >> name;
			if (girls.find(name) != girls.end())
				girls.erase(name);
			if (boys.find(name) != boys.end())
				boys.erase(name);
		}
		else if (cmd == 3) {
			string start, end; int gender; cin >> start >> end >> gender;
			int girlCount = girls.order_of_key(end) - girls.order_of_key(start);
			int boyCount = boys.order_of_key(end) - boys.order_of_key(start);
			if (gender == 0)
				printf("%d\n", girlCount+boyCount);
			else if (gender == 1) 
				printf("%d\n", boyCount);
			else if (gender == 2)
				printf("%d\n", girlCoungirlCount);
		}
		else throw cmd;
	}
}
