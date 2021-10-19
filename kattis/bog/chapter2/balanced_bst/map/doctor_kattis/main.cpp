#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
unordered_map<string, int> inf, arr;

struct cat {
	string name;
	int level;
	int arr;
	cat(string name, int level, int arr) : name(name), level(level), arr(arr) {}
	bool operator < (const cat& a) const {
		if (level != a.level)
			return level > a.level;
		return arr < a.arr;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	set<cat> clinic;
	while (n--) {
		int cmd; cin >> cmd;
		if (cmd == 0) {
			string name; int x; cin >> name >> x;
			inf[name] = x;
			arr[name] = ++cnt;
			clinic.insert(cat(name, inf[name], arr[name]));
		}
		else if (cmd == 1) {
			string name; int x; cin >> name >> x;
			auto it = clinic.lower_bound(cat(name, inf[name], arr[name]));
			clinic.erase(it);
			inf[name] += x;
			clinic.insert(cat(name, inf[name], arr[name]));
		}
		else if (cmd == 2) {
			string name; cin >> name;
			auto it = clinic.lower_bound(cat(name, inf[name], arr[name]));
			clinic.erase(it);
		}
		else if (cmd == 3) {
			if (clinic.size())
				printf("%s\n", (*clinic.begin()).name.c_str());
			else
				printf("The clinic is empty\n");
		}
		else throw cmd;
	}
}
