#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int day = 0;
	while (getline(cin, s) && s == "OPEN") {
		day++;
		unordered_map<string, int> enter;
		map<string, int> tim;
		while (getline(cin, s) && s != "CLOSE") {
			stringstream ss(s);
			string cmd, name; int t; ss >> cmd >> name >> t;
			if (cmd == "ENTER")
				enter[name] = t;
			else if (cmd == "EXIT")
				tim[name] += t-enter[name];
			else throw cmd;
		}
		printf("Day %d\n", day);
		for (auto& [name,t] : tim)
			printf("%s $%.2lf\n", name.c_str(), t*0.1);
		printf("\n");
	}

}
