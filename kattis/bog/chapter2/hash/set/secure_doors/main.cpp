#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	unordered_set<string> build;
	while (n--) {
		string cmd, pers; cin >> cmd >> pers;
		if (cmd == "entry") {
			if (build.count(pers))
				printf("%s entered (ANOMALY)\n", pers.c_str());
			else
				printf("%s entered\n", pers.c_str());
			build.insert(pers);
		}
		else if (cmd == "exit") {
			if (build.count(pers))
				printf("%s exited\n", pers.c_str());
			else
				printf("%s exited (ANOMALY)\n", pers.c_str());
			build.erase(pers);
		}
	}
}
